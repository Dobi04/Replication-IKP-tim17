#pragma once

/** @brief Planned sender thread for replication frames. */
class SenderThread
{
public:
    /** @brief Start the sender thread. */
    bool Start();
    /** @brief Stop the sender thread. */
    void Stop();
};