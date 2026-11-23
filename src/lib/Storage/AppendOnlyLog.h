#pragma once

#include <stdint.h>

/** @brief Callback invoked while reading a log record. */
typedef bool (*LogRecordCallback)(const void* record, uint32_t recordSize, void* context);

/** @brief Append-only binary message log. */
class AppendOnlyLog
{
public:
    /** @brief Construct a closed log. */
    AppendOnlyLog();
    /** @brief Close the log. */
    ~AppendOnlyLog();
    /** @brief Open or create a log file. */
    bool Open(const char* path);
    /** @brief Append a batch of records. */
    bool AppendBatch(const void* records, uint32_t count);
    /** @brief Flush buffered log data to storage. */
    bool Flush();
    /** @brief Read every record and invoke callback. */
    bool ReadAll(LogRecordCallback callback, void* context);
    /** @brief Close the log file. */
    void Close();
private:
    void* implementation;
};