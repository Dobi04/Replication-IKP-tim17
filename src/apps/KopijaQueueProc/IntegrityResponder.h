#pragma once

/** @brief Planned responder for integrity update requests. */
class IntegrityResponder
{
public:
    /** @brief Start the responder. */
    bool Start();
    /** @brief Stop the responder. */
    void Stop();
};