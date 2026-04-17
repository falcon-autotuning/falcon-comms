#include "falcon-comms/commands_definitions.hpp"

// ============================================================================
// CommandBase
// ============================================================================
CommandBase::CommandBase() = default;
CommandBase::CommandBase(const CommandBase &) = default;
CommandBase::CommandBase(CommandBase &&) = default;
CommandBase &CommandBase::operator=(const CommandBase &) = default;
CommandBase &CommandBase::operator=(CommandBase &&) = default;
CommandBase::~CommandBase() = default;

// ============================================================================
// MeasureCommand
// ============================================================================
MeasureCommand::MeasureCommand() : timestamp(0) {}
MeasureCommand::MeasureCommand(const MeasureCommand &) = default;
MeasureCommand::MeasureCommand(MeasureCommand &&) = default;
MeasureCommand &MeasureCommand::operator=(const MeasureCommand &) = default;
MeasureCommand &MeasureCommand::operator=(MeasureCommand &&) = default;
MeasureCommand::~MeasureCommand() = default;

std::string MeasureCommand::command_name() const { return NAME; }

nlohmann::json MeasureCommand::to_json() const {
  nlohmann::json j;
  j["request"] = request;
  j["timestamp"] = timestamp;
  return j;
}

MeasureCommand MeasureCommand::from_json(const nlohmann::json &j) {
  MeasureCommand obj;
  if (j.contains("request"))
    j.at("request").get_to(obj.request);
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}

// ============================================================================
// MeasureResponse
// ============================================================================
MeasureResponse::MeasureResponse() : timestamp(0) {}
MeasureResponse::MeasureResponse(const MeasureResponse &) = default;
MeasureResponse::MeasureResponse(MeasureResponse &&) = default;
MeasureResponse &MeasureResponse::operator=(const MeasureResponse &) = default;
MeasureResponse &MeasureResponse::operator=(MeasureResponse &&) = default;
MeasureResponse::~MeasureResponse() = default;

std::string MeasureResponse::command_name() const { return NAME; }

nlohmann::json MeasureResponse::to_json() const {
  nlohmann::json j;
  j["channel"] = channel;
  j["stream"] = stream;
  j["timestamp"] = timestamp;
  return j;
}

MeasureResponse MeasureResponse::from_json(const nlohmann::json &j) {
  MeasureResponse obj;
  if (j.contains("channel"))
    j.at("channel").get_to(obj.channel);
  if (j.contains("stream"))
    j.at("stream").get_to(obj.stream);
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}

// ============================================================================
// StateRequest
// ============================================================================
StateRequest::StateRequest() : timestamp(0) {}
StateRequest::StateRequest(const StateRequest &) = default;
StateRequest::StateRequest(StateRequest &&) = default;
StateRequest &StateRequest::operator=(const StateRequest &) = default;
StateRequest &StateRequest::operator=(StateRequest &&) = default;
StateRequest::~StateRequest() = default;

std::string StateRequest::command_name() const { return NAME; }

nlohmann::json StateRequest::to_json() const {
  nlohmann::json j;
  j["timestamp"] = timestamp;
  return j;
}

StateRequest StateRequest::from_json(const nlohmann::json &j) {
  StateRequest obj;
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}

// ============================================================================
// StateResponse
// ============================================================================
StateResponse::StateResponse() : timestamp(0) {}
StateResponse::StateResponse(const StateResponse &) = default;
StateResponse::StateResponse(StateResponse &&) = default;
StateResponse &StateResponse::operator=(const StateResponse &) = default;
StateResponse &StateResponse::operator=(StateResponse &&) = default;
StateResponse::~StateResponse() = default;

std::string StateResponse::command_name() const { return NAME; }

nlohmann::json StateResponse::to_json() const {
  nlohmann::json j;
  j["response"] = response;
  j["timestamp"] = timestamp;
  return j;
}

StateResponse StateResponse::from_json(const nlohmann::json &j) {
  StateResponse obj;
  if (j.contains("response"))
    j.at("response").get_to(obj.response);
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}

// ============================================================================
// PortRequest
// ============================================================================
PortRequest::PortRequest() : timestamp(0) {}
PortRequest::PortRequest(const PortRequest &) = default;
PortRequest::PortRequest(PortRequest &&) = default;
PortRequest &PortRequest::operator=(const PortRequest &) = default;
PortRequest &PortRequest::operator=(PortRequest &&) = default;
PortRequest::~PortRequest() = default;

std::string PortRequest::command_name() const { return NAME; }

nlohmann::json PortRequest::to_json() const {
  nlohmann::json j;
  j["timestamp"] = timestamp;
  return j;
}

PortRequest PortRequest::from_json(const nlohmann::json &j) {
  PortRequest obj;
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}

// ============================================================================
// PortPayload
// ============================================================================
PortPayload::PortPayload() : timestamp(0) {}
PortPayload::PortPayload(const PortPayload &) = default;
PortPayload::PortPayload(PortPayload &&) = default;
PortPayload &PortPayload::operator=(const PortPayload &) = default;
PortPayload &PortPayload::operator=(PortPayload &&) = default;
PortPayload::~PortPayload() = default;

std::string PortPayload::command_name() const { return NAME; }

nlohmann::json PortPayload::to_json() const {
  nlohmann::json j;
  j["meters"] = meters;
  j["timestamp"] = timestamp;
  j["knobs"] = knobs;
  return j;
}

PortPayload PortPayload::from_json(const nlohmann::json &j) {
  PortPayload obj;
  if (j.contains("knobs"))
    j.at("knobs").get_to(obj.knobs);
  if (j.contains("meters"))
    j.at("meters").get_to(obj.meters);
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}

// ============================================================================
// DeviceConfigRequest
// ============================================================================
DeviceConfigRequest::DeviceConfigRequest() : timestamp(0) {}
DeviceConfigRequest::DeviceConfigRequest(const DeviceConfigRequest &) = default;
DeviceConfigRequest::DeviceConfigRequest(DeviceConfigRequest &&) = default;
DeviceConfigRequest &
DeviceConfigRequest::operator=(const DeviceConfigRequest &) = default;
DeviceConfigRequest &
DeviceConfigRequest::operator=(DeviceConfigRequest &&) = default;
DeviceConfigRequest::~DeviceConfigRequest() = default;

std::string DeviceConfigRequest::command_name() const { return NAME; }

nlohmann::json DeviceConfigRequest::to_json() const {
  nlohmann::json j;
  j["timestamp"] = timestamp;
  return j;
}

DeviceConfigRequest DeviceConfigRequest::from_json(const nlohmann::json &j) {
  DeviceConfigRequest obj;
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}

// ============================================================================
// DeviceConfigResponse
// ============================================================================
DeviceConfigResponse::DeviceConfigResponse() : timestamp(0) {}
DeviceConfigResponse::DeviceConfigResponse(const DeviceConfigResponse &) =
    default;
DeviceConfigResponse::DeviceConfigResponse(DeviceConfigResponse &&) = default;
DeviceConfigResponse &
DeviceConfigResponse::operator=(const DeviceConfigResponse &) = default;
DeviceConfigResponse &
DeviceConfigResponse::operator=(DeviceConfigResponse &&) = default;
DeviceConfigResponse::~DeviceConfigResponse() = default;

std::string DeviceConfigResponse::command_name() const { return NAME; }

nlohmann::json DeviceConfigResponse::to_json() const {
  nlohmann::json j;
  j["response"] = response;
  j["timestamp"] = timestamp;
  return j;
}

DeviceConfigResponse DeviceConfigResponse::from_json(const nlohmann::json &j) {
  DeviceConfigResponse obj;
  if (j.contains("response"))
    j.at("response").get_to(obj.response);
  if (j.contains("timestamp"))
    j.at("timestamp").get_to(obj.timestamp);
  return obj;
}
