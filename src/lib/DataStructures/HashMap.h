#pragma once

#include <stdint.h>

/** @brief Hash map with uint64_t keys and pointer values. */
class HashMap
{
public:
    /** @brief Construct an empty hash map. */
    HashMap();
    /** @brief Destroy the hash map. */
    ~HashMap();
    /** @brief Store a value under an integer key. */
    bool Put(uint64_t key, void* value);
    /** @brief Retrieve a value by integer key. */
    void* Get(uint64_t key) const;
    /** @brief Remove an integer key. */
    bool Remove(uint64_t key);
    /** @brief Return true if an integer key exists. */
    bool Contains(uint64_t key) const;
    /** @brief Return the number of entries. */
    uint32_t Size() const;
};

/** @brief Hash map with null-terminated string keys and pointer values. */
class StringHashMap
{
public:
    /** @brief Construct an empty string-keyed hash map. */
    StringHashMap();
    /** @brief Destroy the string-keyed hash map. */
    ~StringHashMap();
    /** @brief Store a value under a string key. */
    bool Put(const char* key, void* value);
    /** @brief Retrieve a value by string key. */
    void* Get(const char* key) const;
    /** @brief Remove a string key. */
    bool Remove(const char* key);
    /** @brief Return true if a string key exists. */
    bool Contains(const char* key) const;
    /** @brief Return the number of entries. */
    uint32_t Size() const;
};