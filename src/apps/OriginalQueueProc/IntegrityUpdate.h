#pragma once

#include <stdint.h>

/** @brief Planned integrity update processor. */
class IntegrityUpdate
{
public:
    /** @brief Process an integrity update batch. */
    bool Process(const void* records, uint32_t count);
};