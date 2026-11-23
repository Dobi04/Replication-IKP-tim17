#pragma once

#include <stdint.h>

/** @brief Launches a queue processor process. */
class ProcessLauncher
{
public:
    /** @brief Construct a process launcher. */
    ProcessLauncher();
    /** @brief Destroy the process launcher. */
    ~ProcessLauncher();
    /** @brief Launch a queue processor executable. */
    bool Launch(const char* executablePath, const char* arguments, uint32_t* processId);
private:
    void* implementation;
};