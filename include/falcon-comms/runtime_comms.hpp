#pragma once

#include "commands_definitions.hpp"
#include "falcon-comms/export.h"
#include "natsManager.hpp"

namespace falcon::comms {

/**
 * @brief Communication service for Runtime operations
 *
 * Handles DeviceConfigRequest, DeviceConfigResponse, PortRequest, and
 * PortPayload.
 */
class FALCON_COMMS_API RuntimeComms {
public:
  RuntimeComms();
  RuntimeComms(const RuntimeComms &) = default;
  RuntimeComms(RuntimeComms &&) = delete;
  RuntimeComms &operator=(const RuntimeComms &) = delete;
  RuntimeComms &operator=(RuntimeComms &&) = delete;
  explicit RuntimeComms(NatsManager &hub) : hub_(hub) {}
  ~RuntimeComms() = default;

  /**
   * @brief Subscribe to device config with a callback
   * @param timeout_ms the timeout in milliseconds to wait
   * @param time current time
   * @return DeviceConfigResponse if successful
   */
  DeviceConfigResponse subscribe_config_response(int timeout_ms, int time);

  /**
   * @brief Subscribe to ports with a callback
   * @param timeout_ms the timeout in milliseconds to wait
   * @param time current time
   * @return  PortPayloadif successful
   */
  PortPayload subscribe_port_payload(int timeout_ms, int time);

private:
  NatsManager &hub_;
};

} // namespace falcon::comms
