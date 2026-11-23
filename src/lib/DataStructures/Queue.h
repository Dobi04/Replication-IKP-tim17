#pragma once

#include <stdint.h>

/** @brief FIFO queue for non-owning void pointers. */
class Queue
{
public:
    /** @brief Construct an empty queue. */
    Queue();
    /** @brief Destroy the queue. */
    ~Queue();
    /** @brief Add a value to the back of the queue. */
    bool Push(void* value);
    /** @brief Remove and return the front value. */
    void* Pop();
    /** @brief Return the front value without removing it. */
    void* Peek() const;
    /** @brief Return the number of queued values. */
    uint32_t Size() const;
    /** @brief Return true when the queue is empty. */
    bool IsEmpty() const;
    /** @brief Remove all queued values. */
    void Clear();
private:
    void* implementation;
};