#pragma once

/** @brief Planned receiver thread for the copy queue processor. */
class ReceiverThread
{
public:
    /** @brief Start the receiver thread. */
    bool Start();
    /** @brief Stop the receiver thread. */
    void Stop();
};