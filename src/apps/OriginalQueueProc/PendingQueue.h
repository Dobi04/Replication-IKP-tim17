#pragma once

#include <stdint.h>

/** @brief Queue of messages awaiting acknowledgement. */
class PendingQueue
{
public:
    /** @brief Add a message ID to the pending queue. */
    bool Add(uint64_t messageId);
    /** @brief Remove a message ID after acknowledgement. */
    bool Remove(uint64_t messageId);
    /** @brief Return the number of pending messages. */
    uint32_t Size() const;
};