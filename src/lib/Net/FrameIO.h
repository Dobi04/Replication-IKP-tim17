#pragma once

#include <stdint.h>
#include "Common/Protocol.h"
#include "TcpConnection.h"

/** @brief Write a complete protocol frame to a TCP connection. */
bool WriteFrame(TcpConnection* connection, uint8_t type, const uint8_t* body, uint32_t bodyLength);
/** @brief Read one complete protocol frame from a TCP connection. */
bool ReadFrame(TcpConnection* connection, FrameHeader* header, uint8_t* bodyBuffer, uint32_t bufferCapacity);