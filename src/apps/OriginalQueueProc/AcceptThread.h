#pragma once

/** @brief Planned thread for accepting device connections. */
class AcceptThread
{
public:
    /** @brief Start the accept thread. */
    bool Start();
    /** @brief Stop the accept thread. */
    void Stop();
};