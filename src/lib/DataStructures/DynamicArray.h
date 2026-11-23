#pragma once

#include <stdint.h>

/** @brief Growable array for non-owning pointer values. */
class DynamicArray
{
public:
    /** @brief Construct an empty dynamic array. */
    DynamicArray();
    /** @brief Destroy the dynamic array. */
    ~DynamicArray();
    /** @brief Append a value. */
    bool Push(void* value);
    /** @brief Remove and return the last value. */
    void* Pop();
    /** @brief Return a value at an index. */
    void* At(uint32_t index) const;
    /** @brief Replace a value at an index. */
    bool Set(uint32_t index, void* value);
    /** @brief Return the number of values. */
    uint32_t Size() const;
    /** @brief Return true when the array is empty. */
    bool IsEmpty() const;
    /** @brief Remove all values. */
    void Clear();
private:
    void* implementation;
};