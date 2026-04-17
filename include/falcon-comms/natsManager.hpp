#pragma once

#include "falcon-comms/export.h"
#include <functional>
#include <mutex>
#include <nats/nats.h>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <vector>
const int MAX_TIMEOUT_MS = 60000; // 60 seconds

namespace falcon::comms {
struct SubscriptionData {
  natsSubscription *subscription;
  std::function<void(const std::string &)> *callback;
  std::string subject;
};

/**
 * @brief Lazy-initialized NATS hub for messaging with JetStream support
 */
class FALCON_COMMS_API NatsManager {
public:
  NatsManager(NatsManager &&) = delete;
  NatsManager &operator=(const NatsManager &) = delete;
  NatsManager(const NatsManager &) = delete;
  NatsManager &operator=(NatsManager &&) = delete;
  explicit NatsManager(std::vector<SubscriptionData> subscriptions)
      : subscriptions_(std::move(subscriptions)) {}
  static NatsManager &instance();

  void publish(const std::string &subject, const std::string &message);
  void publish_json(const std::string &subject, const nlohmann::json &data);
  std::optional<std::string> request(const std::string &subject,
                                     const std::string &request,
                                     int timeout_ms = MAX_TIMEOUT_MS);
  std::optional<nlohmann::json> request_json(const std::string &subject,
                                             const nlohmann::json &request,
                                             int timeout_ms = MAX_TIMEOUT_MS);
  void subscribe(const std::string &subject,
                 std::function<void(const std::string &)> callback);
  void unsubscribe(const std::string &subject);
  std::vector<std::string> jetstream_pull(const std::string &stream,
                                          const std::string &consumer,
                                          int batch_size = 1);
  jsCtx *get_jetstream_context();
  bool is_connected() const;
  void connect(const std::string &url = "");
  void disconnect();
  ~NatsManager();

private:
  NatsManager();

  void ensure_connected();
  void ensure_jetstream();
  void cleanup_subscriptions();
  void ensure_library_initialized();

  natsConnection *conn_ = nullptr;
  jsCtx *js_ = nullptr;
  mutable std::mutex mutex_;
  std::vector<SubscriptionData> subscriptions_;
};

// Static members at namespace scope (NOT in class)
extern bool g_nats_library_initialized;
extern std::mutex g_nats_library_mutex;

} // namespace falcon::comms
