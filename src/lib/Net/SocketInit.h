#pragma once

#include <winsock2.h>

/** @brief RAII-style wrapper for Winsock initialization and cleanup. */
class SocketInit
{
public:
    /** @brief Initialize Winsock. */
    SocketInit();
    /** @brief Clean up Winsock resources. */
    ~SocketInit();
    /** @brief Return whether initialization succeeded. */
    bool IsInitialized() const;
private:
    bool initialized;
};