#pragma once

/** @brief Planned acknowledgement-processing thread. */
class AckThread
{
public:
    /** @brief Start the acknowledgement thread. */
    bool Start();
    /** @brief Stop the acknowledgement thread. */
    void Stop();
};