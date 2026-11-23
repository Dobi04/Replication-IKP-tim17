#pragma once

#include <stdint.h>

/** @brief Protocol message types. */
enum class MessageType : uint8_t
{
    /** @brief Request to connect to a queue. */
    CONNECT = 1,
    /** @brief Successful connection reply. */
    CONNECT_REPLY = 2,
    /** @brief Queue is busy. */
    BUSY = 3,
    /** @brief Hello message exchanged by master processes. */
    PAIR_HELLO = 4,
    /** @brief Reply to a pair hello message. */
    PAIR_HELLO_REPLY = 5,
    /** @brief Data received from a simulated device. */
    DEVICE_DATA = 6,
    /** @brief Data frame sent through the replication protocol. */
    DATA = 7,
    /** @brief Positive acknowledgement. */
    ACK = 8,
    /** @brief Request for queued messages. */
    GET_MESSAGES = 9,
    /** @brief Response to a message request. */
    RESPONSE = 10,
    /** @brief Protocol error. */
    ERROR_MSG = 11
};