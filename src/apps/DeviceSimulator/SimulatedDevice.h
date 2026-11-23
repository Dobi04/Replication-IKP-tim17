#pragma once

#include <stdint.h>

/** @brief Configuration for one simulated device. */
struct SimulatedDeviceConfig
{
    uint32_t deviceNumber;
    uint32_t messageCount;
};

/** @brief Single simulated device. */
class SimulatedDevice
{
public:
    /** @brief Construct a simulated device. */
    SimulatedDevice();
    /** @brief Destroy the simulated device. */
    ~SimulatedDevice();
    /** @brief Configure the simulated device. */
    bool Configure(const SimulatedDeviceConfig* config);
    /** @brief Run the simulated device workload. */
    bool Run();
};