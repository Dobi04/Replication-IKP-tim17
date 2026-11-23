#pragma once

#include <stdint.h>

/** @brief Fixed-capacity ring buffer for non-owning pointers. */
class RingBuffer
{
public:
    /** @brief Construct a ring buffer with the requested capacity. */
    RingBuffer(uint32_t capacity);
    /** @brief Destroy the ring buffer. */
    ~RingBuffer();
    /** @brief Add a value; return false when full. */
    bool Push(void* value);
    /** @brief Remove and return the oldest value. */
    void* Pop();
    /** @brief Peek at the oldest value. */
    void* Peek() const;
    /** @brief Return the current number of values. */
    uint32_t Size() const;
    /** @brief Return true when the buffer is empty. */
    bool IsEmpty() const;
    /** @brief Remove all values. */
    void Clear();
private:
    void* implementation;
};