#pragma once

/** @brief Planned worker for processing device data. */
class DeviceWorker
{
public:
    /** @brief Start processing device data. */
    bool Start();
    /** @brief Stop processing device data. */
    void Stop();
};