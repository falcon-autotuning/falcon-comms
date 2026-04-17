#include "falcon-comms/commands_definitions.hpp"

// ============================================================================
// CommandBase
// ============================================================================
CommandBase::CommandBase() = default;
CommandBase::CommandBase(const CommandBase &) = default;
CommandBase::CommandBase(CommandBase &&) noexcept = default;
CommandBase &CommandBase::operator=(const CommandBase &) = default;
CommandBase &CommandBase::operator=(CommandBase &&) noexcept = default;
CommandBase::~CommandBase() = default;

// ============================================================================
// MeasureCommand
// ============================================================================
MeasureCommand::MeasureCommand() = default;
MeasureCommand::MeasureCommand(const MeasureCommand &) = default;
MeasureCommand::MeasureCommand(MeasureCommand &&) noexcept = default;
MeasureCommand &MeasureCommand::operator=(const MeasureCommand &) = default;
MeasureCommand &MeasureCommand::operator=(MeasureCommand &&) noexcept = default;
MeasureCommand::~MeasureCommand() = default;

std::string MeasureCommand::command_name() const { return NAME; }

nlohmann::json MeasureCommand::to_json() const {
  nlohmann::json json;
  json["request"] = request;
  json["timestamp"] = timestamp;
  return json;
}

MeasureCommand MeasureCommand::from_json(const nlohmann::json &j) {
  MeasureCommand obj;
  if (j.contains("request")) {
    j.at("request").get_to(obj.request);
  }
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}

// ============================================================================
// MeasureResponse
// ============================================================================
MeasureResponse::MeasureResponse() = default;
MeasureResponse::MeasureResponse(const MeasureResponse &) = default;
MeasureResponse::MeasureResponse(MeasureResponse &&) noexcept = default;
MeasureResponse &MeasureResponse::operator=(const MeasureResponse &) = default;
MeasureResponse &
MeasureResponse::operator=(MeasureResponse &&) noexcept = default;
MeasureResponse::~MeasureResponse() = default;

std::string MeasureResponse::command_name() const { return NAME; }

nlohmann::json MeasureResponse::to_json() const {
  nlohmann::json json;
  json["channel"] = channel;
  json["stream"] = stream;
  json["timestamp"] = timestamp;
  return json;
}

MeasureResponse MeasureResponse::from_json(const nlohmann::json &j) {
  MeasureResponse obj;
  if (j.contains("channel")) {
    j.at("channel").get_to(obj.channel);
  }
  if (j.contains("stream")) {
    j.at("stream").get_to(obj.stream);
  }
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}

// ============================================================================
// StateRequest
// ============================================================================
StateRequest::StateRequest() = default;
StateRequest::StateRequest(const StateRequest &) = default;
StateRequest::StateRequest(StateRequest &&) noexcept = default;
StateRequest &StateRequest::operator=(const StateRequest &) = default;
StateRequest &StateRequest::operator=(StateRequest &&) noexcept = default;
StateRequest::~StateRequest() = default;

std::string StateRequest::command_name() const { return NAME; }

nlohmann::json StateRequest::to_json() const {
  nlohmann::json json;
  json["timestamp"] = timestamp;
  return json;
}

StateRequest StateRequest::from_json(const nlohmann::json &j) {
  StateRequest obj;
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}

// ============================================================================
// StateResponse
// ============================================================================
StateResponse::StateResponse() = default;
StateResponse::StateResponse(const StateResponse &) = default;
StateResponse::StateResponse(StateResponse &&) noexcept = default;
StateResponse &StateResponse::operator=(const StateResponse &) = default;
StateResponse &StateResponse::operator=(StateResponse &&) noexcept = default;
StateResponse::~StateResponse() = default;

std::string StateResponse::command_name() const { return NAME; }

nlohmann::json StateResponse::to_json() const {
  nlohmann::json json;
  json["response"] = response;
  json["timestamp"] = timestamp;
  return json;
}

StateResponse StateResponse::from_json(const nlohmann::json &j) {
  StateResponse obj;
  if (j.contains("response")) {
    j.at("response").get_to(obj.response);
  }
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}

// ============================================================================
// PortRequest
// ============================================================================
PortRequest::PortRequest() = default;
PortRequest::PortRequest(const PortRequest &) = default;
PortRequest::PortRequest(PortRequest &&) noexcept = default;
PortRequest &PortRequest::operator=(const PortRequest &) = default;
PortRequest &PortRequest::operator=(PortRequest &&) noexcept = default;
PortRequest::~PortRequest() = default;

std::string PortRequest::command_name() const { return NAME; }

nlohmann::json PortRequest::to_json() const {
  nlohmann::json json;
  json["timestamp"] = timestamp;
  return json;
}

PortRequest PortRequest::from_json(const nlohmann::json &j) {
  PortRequest obj;
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}

// ============================================================================
// PortPayload
// ============================================================================
PortPayload::PortPayload() = default;
PortPayload::PortPayload(const PortPayload &) = default;
PortPayload::PortPayload(PortPayload &&) noexcept = default;
PortPayload &PortPayload::operator=(const PortPayload &) = default;
PortPayload &PortPayload::operator=(PortPayload &&) noexcept = default;
PortPayload::~PortPayload() = default;

std::string PortPayload::command_name() const { return NAME; }

nlohmann::json PortPayload::to_json() const {
  nlohmann::json json;
  json["meters"] = meters;
  json["timestamp"] = timestamp;
  json["knobs"] = knobs;
  return json;
}

PortPayload PortPayload::from_json(const nlohmann::json &j) {
  PortPayload obj;
  if (j.contains("knobs")) {
    j.at("knobs").get_to(obj.knobs);
  }
  if (j.contains("meters")) {
    j.at("meters").get_to(obj.meters);
  }
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}

// ============================================================================
// DeviceConfigRequest
// ============================================================================
DeviceConfigRequest::DeviceConfigRequest() = default;
DeviceConfigRequest::DeviceConfigRequest(const DeviceConfigRequest &) = default;
DeviceConfigRequest::DeviceConfigRequest(DeviceConfigRequest &&) noexcept =
    default;
DeviceConfigRequest &
DeviceConfigRequest::operator=(const DeviceConfigRequest &) = default;
DeviceConfigRequest &
DeviceConfigRequest::operator=(DeviceConfigRequest &&) noexcept = default;
DeviceConfigRequest::~DeviceConfigRequest() = default;

std::string DeviceConfigRequest::command_name() const { return NAME; }

nlohmann::json DeviceConfigRequest::to_json() const {
  nlohmann::json json;
  json["timestamp"] = timestamp;
  return json;
}

DeviceConfigRequest DeviceConfigRequest::from_json(const nlohmann::json &j) {
  DeviceConfigRequest obj;
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}

// ============================================================================
// DeviceConfigResponse
// ============================================================================
DeviceConfigResponse::DeviceConfigResponse() = default;
DeviceConfigResponse::DeviceConfigResponse(const DeviceConfigResponse &) =
    default;
DeviceConfigResponse::DeviceConfigResponse(DeviceConfigResponse &&) noexcept =
    default;
DeviceConfigResponse &
DeviceConfigResponse::operator=(const DeviceConfigResponse &) = default;
DeviceConfigResponse &
DeviceConfigResponse::operator=(DeviceConfigResponse &&) noexcept = default;
DeviceConfigResponse::~DeviceConfigResponse() = default;

std::string DeviceConfigResponse::command_name() const { return NAME; }

nlohmann::json DeviceConfigResponse::to_json() const {
  nlohmann::json json;
  json["response"] = response;
  json["timestamp"] = timestamp;
  return json;
}

DeviceConfigResponse DeviceConfigResponse::from_json(const nlohmann::json &j) {
  DeviceConfigResponse obj;
  if (j.contains("response")) {
    j.at("response").get_to(obj.response);
  }
  if (j.contains("timestamp")) {
    j.at("timestamp").get_to(obj.timestamp);
  }
  return obj;
}
