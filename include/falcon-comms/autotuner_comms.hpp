#pragma once

#include "commands_definitions.hpp"
#include "falcon-comms/export.h"
#include "natsManager.hpp"

namespace falcon::comms {

/**
 * @brief Communication service for Autotuner
 *
 * Handles StateRequest and StateResponse for autotuning operations.
 */
class FALCON_COMMS_API AutotunerComms {
public:
  AutotunerComms();
  AutotunerComms(const AutotunerComms &) = default;
  AutotunerComms(AutotunerComms &&) = delete;
  AutotunerComms &operator=(const AutotunerComms &) = delete;
  AutotunerComms &operator=(AutotunerComms &&) = delete;
  explicit AutotunerComms(NatsManager &hub) : hub_(hub) {}
  ~AutotunerComms();

  /**
   * @brief Subscribe to state responses with a callback
   * @param timeout_ms the timeout in milliseconds to wait
   * @param time current time
   * @return StateResponse if successful
   */
  StateResponse subscribe_state_response(int timeout_ms, int time);

protected:
  NatsManager &hub_;
};

} // namespace falcon::comms
