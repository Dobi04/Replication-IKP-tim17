#pragma once

#include <stdint.h>

/** @brief Entry linking a queue name to process information. */
struct QueueRegistryEntry
{
    char name[128];
    uint16_t port;
    uint32_t processId;
};

/** @brief Registry of named replication queues. */
class QueueRegistry
{
public:
    /** @brief Construct an empty registry. */
    QueueRegistry();
    /** @brief Destroy the registry. */
    ~QueueRegistry();
    /** @brief Register or update a queue entry. */
    bool Register(const char* name, uint16_t port, uint32_t processId);
    /** @brief Find a queue entry by name. */
    const QueueRegistryEntry* Find(const char* name) const;
    /** @brief Return the number of registered queues. */
    uint32_t Size() const;
    /** @brief Clear all queue entries. */
    void Clear();
private:
    void* implementation;
};