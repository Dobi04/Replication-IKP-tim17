#pragma once

#include <stdint.h>

/** @brief Fixed protocol frame header. */
struct FrameHeader
{
    uint8_t version;
    uint8_t type;
    uint32_t bodyLength;
};

/** @brief Device measurement payload. */
struct DataBody
{
    uint64_t messageId;
    uint32_t deviceNumber;
    float current;
    float voltage;
    float power;
};

/** @brief Acknowledgement payload. */
struct AckBody
{
    uint64_t messageId;
};

/** @brief Serialize a frame header into a six-byte buffer. */
bool SerializeFrameHeader(const FrameHeader* header, uint8_t* buffer);
/** @brief Deserialize a frame header from a six-byte buffer. */
bool DeserializeFrameHeader(const uint8_t* buffer, FrameHeader* header);
/** @brief Serialize a DATA payload into a 24-byte buffer. */
bool SerializeDataBody(const DataBody* body, uint8_t* buffer);
/** @brief Deserialize a DATA payload from a 24-byte buffer. */
bool DeserializeDataBody(const uint8_t* buffer, DataBody* body);
/** @brief Serialize an ACK payload into an eight-byte buffer. */
bool SerializeAckBody(const AckBody* body, uint8_t* buffer);
/** @brief Deserialize an ACK payload from an eight-byte buffer. */
bool DeserializeAckBody(const uint8_t* buffer, AckBody* body);