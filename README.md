# Replication - IKP Project 17

Replication is a skeleton Visual Studio solution for an original and copy master replication system.

## Projects

- **Common**: Protocol constants, message types, serialization, and byte-order helpers.
- **DataStructures**: Data structures used across the replication components.
- **Net**: Winsock initialization and TCP framing helpers.
- **Storage**: Append-only logging and log indexing.
- **ClientLib**: Public client interface for queue operations.
- **OriginalMaster**: Original-side master process listening on port 5000.
- **KopijaMaster**: Copy-side master process listening on port 6000.
- **OriginalQueueProc**: Original-side queue processing executable.
- **KopijaQueueProc**: Copy-side queue processing executable.
- **DeviceSimulator**: Command-line simulated device application.
- **DataStructures.Tests**: Data structure test skeletons.
- **Protocol.Tests**: Protocol and byte-order test skeletons.
- **Storage.Tests**: Storage test skeletons.
- **StressTests**: Stress and integrity test skeletons.

## Build

Open Replication.sln, select the x64 platform and Debug configuration, then build the solution.

The C++ standard library is prohibited in the codebase. STL containers and threading or synchronization headers are not used.