#pragma once

#include <stdint.h>
#include <winsock2.h>

/** @brief TCP connection socket. */
class TcpConnection
{
public:
    /** @brief Construct a closed connection. */
    TcpConnection();
    /** @brief Close the connection. */
    ~TcpConnection();
    /** @brief Connect to a host and port. */
    bool Connect(const char* host, uint16_t port);
    /** @brief Send all bytes in a buffer. */
    bool SendAll(const uint8_t* buffer, uint32_t length);
    /** @brief Receive exactly the requested byte count. */
    bool RecvAll(uint8_t* buffer, uint32_t length);
    /** @brief Close the connection. */
    void Close();
private:
    SOCKET socketHandle;
};