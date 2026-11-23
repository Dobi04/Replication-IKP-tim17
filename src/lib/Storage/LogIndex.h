#pragma once

#include <stdint.h>

/** @brief Message-ID index rebuilt from the append-only log. */
class LogIndex
{
public:
    /** @brief Construct an empty log index. */
    LogIndex();
    /** @brief Destroy the log index. */
    ~LogIndex();
    /** @brief Rebuild the index by reading the log. */
    bool Rebuild(const char* logPath);
    /** @brief Return true if a message ID is already present. */
    bool Contains(uint64_t messageId) const;
    /** @brief Return the greatest indexed message ID. */
    uint64_t GetMaxId() const;
private:
    void* implementation;
};