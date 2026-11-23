#pragma once

/** @brief Local message log wrapper for the original queue processor. */
class LocalLog
{
public:
    /** @brief Open a local log file. */
    bool Open(const char* path);
    /** @brief Close the local log file. */
    void Close();
};