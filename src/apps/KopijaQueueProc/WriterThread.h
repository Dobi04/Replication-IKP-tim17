#pragma once

/** @brief Planned writer thread for the copy queue processor. */
class WriterThread
{
public:
    /** @brief Start the writer thread. */
    bool Start();
    /** @brief Stop the writer thread. */
    void Stop();
};