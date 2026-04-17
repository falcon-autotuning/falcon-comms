#pragma once
#include "falcon-comms/export.h"
#include <nlohmann/json.hpp>
#include <string>

struct FALCON_COMMS_API CommandBase {
  CommandBase();
  CommandBase(const CommandBase &);
  CommandBase(CommandBase &&) noexcept;
  CommandBase &operator=(const CommandBase &);
  CommandBase &operator=(CommandBase &&) noexcept;
  virtual ~CommandBase();

  [[nodiscard]] virtual std::string command_name() const = 0;
  [[nodiscard]] virtual nlohmann::json to_json() const = 0;
};

// MeasureCommand
struct FALCON_COMMS_API MeasureCommand : public CommandBase {
  static constexpr const char *NAME = "MEASURE_COMMAND";
  int timestamp = 0;
  std::string request;

  MeasureCommand();
  MeasureCommand(const MeasureCommand &);
  MeasureCommand(MeasureCommand &&) noexcept;
  MeasureCommand &operator=(const MeasureCommand &);
  MeasureCommand &operator=(MeasureCommand &&) noexcept;
  ~MeasureCommand() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static MeasureCommand from_json(const nlohmann::json &j);
};

// MeasureResponse
struct FALCON_COMMS_API MeasureResponse : public CommandBase {
  static constexpr const char *NAME = "MEASURE_RESPONSE";
  std::string stream;
  int timestamp = 0;
  std::string channel;

  MeasureResponse();
  MeasureResponse(const MeasureResponse &);
  MeasureResponse(MeasureResponse &&) noexcept;
  MeasureResponse &operator=(const MeasureResponse &);
  MeasureResponse &operator=(MeasureResponse &&) noexcept;
  ~MeasureResponse() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static MeasureResponse from_json(const nlohmann::json &j);
};

// StateRequest
struct FALCON_COMMS_API StateRequest : public CommandBase {
  static constexpr const char *NAME = "STATE_REQUEST";
  int timestamp = 0;

  StateRequest();
  StateRequest(const StateRequest &);
  StateRequest(StateRequest &&) noexcept;
  StateRequest &operator=(const StateRequest &);
  StateRequest &operator=(StateRequest &&) noexcept;
  ~StateRequest() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static StateRequest from_json(const nlohmann::json &j);
};

// StateResponse
struct FALCON_COMMS_API StateResponse : public CommandBase {
  static constexpr const char *NAME = "STATE_RESPONSE";
  std::string response;
  int timestamp = 0;

  StateResponse();
  StateResponse(const StateResponse &);
  StateResponse(StateResponse &&) noexcept;
  StateResponse &operator=(const StateResponse &);
  StateResponse &operator=(StateResponse &&) noexcept;
  ~StateResponse() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static StateResponse from_json(const nlohmann::json &j);
};

// PortRequest
struct FALCON_COMMS_API PortRequest : public CommandBase {
  static constexpr const char *NAME = "PORT_REQUEST";
  int timestamp = 0;

  PortRequest();
  PortRequest(const PortRequest &);
  PortRequest(PortRequest &&) noexcept;
  PortRequest &operator=(const PortRequest &);
  PortRequest &operator=(PortRequest &&) noexcept;
  ~PortRequest() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static PortRequest from_json(const nlohmann::json &j);
};

// PortPayload
struct FALCON_COMMS_API PortPayload : public CommandBase {
  static constexpr const char *NAME = "PORT_PAYLOAD";
  std::string knobs;
  std::string meters;
  int timestamp = 0;

  PortPayload();
  PortPayload(const PortPayload &);
  PortPayload(PortPayload &&) noexcept;
  PortPayload &operator=(const PortPayload &);
  PortPayload &operator=(PortPayload &&) noexcept;
  ~PortPayload() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static PortPayload from_json(const nlohmann::json &j);
};

// DeviceConfigRequest
struct FALCON_COMMS_API DeviceConfigRequest : public CommandBase {
  static constexpr const char *NAME = "DEVICE_CONFIG_REQUEST";
  int timestamp = 0;

  DeviceConfigRequest();
  DeviceConfigRequest(const DeviceConfigRequest &);
  DeviceConfigRequest(DeviceConfigRequest &&) noexcept;
  DeviceConfigRequest &operator=(const DeviceConfigRequest &);
  DeviceConfigRequest &operator=(DeviceConfigRequest &&) noexcept;
  ~DeviceConfigRequest() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static DeviceConfigRequest from_json(const nlohmann::json &j);
};

// DeviceConfigResponse
struct FALCON_COMMS_API DeviceConfigResponse : public CommandBase {
  static constexpr const char *NAME = "DEVICE_CONFIG_RESPONSE";
  std::string response;
  int timestamp = 0;

  DeviceConfigResponse();
  DeviceConfigResponse(const DeviceConfigResponse &);
  DeviceConfigResponse(DeviceConfigResponse &&) noexcept;
  DeviceConfigResponse &operator=(const DeviceConfigResponse &);
  DeviceConfigResponse &operator=(DeviceConfigResponse &&) noexcept;
  ~DeviceConfigResponse() override;

  [[nodiscard]] std::string command_name() const override;
  [[nodiscard]] nlohmann::json to_json() const override;
  static DeviceConfigResponse from_json(const nlohmann::json &j);
};
