#pragma once

#include <stdint.h>
#include <winsock2.h>

/** @brief TCP listening socket. */
class TcpListener
{
public:
    /** @brief Construct a closed listener. */
    TcpListener();
    /** @brief Close the listener. */
    ~TcpListener();
    /** @brief Start listening on a port. */
    bool Listen(uint16_t port);
    /** @brief Accept one incoming connection socket. */
    SOCKET Accept();
    /** @brief Close the listening socket. */
    void Close();
private:
    SOCKET socketHandle;
};