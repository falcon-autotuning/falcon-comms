# Falcon Comms - C++ NATS Communication API

A modern C++ implementation of the Falcon communication API using NATS messaging for falcon network DSL interactions.

## Features

- **NATS-based messaging**: High-performance publish/subscribe communication via NATS with JetStream support
- **Multi-component support**: Separate communication APIs for autotuner, routine, and runtime components
- **JSON serialization**: Built-in JSON message formatting via nlohmann_json
- **Logging**: Comprehensive logging with spdlog
- **CRUD operations**: Standard messaging patterns for request/response communication
- **Comprehensive tests**: Unit tests with Google Test framework

## Dependencies

- CMake >= 3.20
- C++17 compiler
- NATS (cnats) >= 3.7.0
- nlohmann_json >= 3.11.2
- spdlog (latest)
- Google Test >= 1.16.0 (for tests)
- OpenSSL (for secure NATS connections)

Dependencies are managed via vcpkg and defined in `vcpkg.json`.

## Building

```bash
make build-debug 

# or 

make build-release
```

## Environment Variables

- `NATS_URL`: NATS connection string used
  - Example: `nats://localhost:4222`
  - Default: Uses Docker services (recommended)

### Connection Priority

Tests will use the `TEST_NATS_URL` environment variable if set, otherwise Docker services will be automatically started.

### Examples

```cpp
// Connect to NATS server
auto manager = falcon::comms::NatsManager("nats://localhost:4222");

// Send autotuner message
auto msg = nlohmann::json{{"action", "tune"}, {"device", "GPU"}};
manager.publish_autotuner(msg);

// Send routine message
manager.publish_routine(msg);

// Send runtime message
manager.publish_runtime(msg);
```

## Testing

### Recommended: Docker-based Testing (Automatic)

The simplest way to run tests - Docker services start automatically:

```bash
make test
```

This will:

1. Start NATS with JetStream in Docker
2. Run all tests
3. Clean up services

## Installation

```bash
make install
```

Installs to `/opt/falcon` by default.
