#pragma once

#include <stdint.h>

/** @brief Port on which the original master listens. */
#define ORIGINAL_MASTER_PORT 5000
/** @brief Port on which the copy master listens. */
#define KOPIJA_MASTER_PORT 6000
/** @brief Protocol format version. */
#define PROTOCOL_VERSION 1
/** @brief Maximum size of one protocol frame body, in bytes. */
#define MAX_FRAME_SIZE 1048576
/** @brief Planned sending window size. */
#define SEND_WINDOW_SIZE 64
/** @brief Maximum number of records in one write batch. */
#define WRITE_BATCH_MAX 64
/** @brief Maximum record count in an integrity update packet. */
#define INTEGRITY_PACKET_MAX_RECORDS 500
/** @brief Serialized size of DataBody. */
#define DATA_BODY_SIZE 24
/** @brief Serialized size of AckBody. */
#define ACK_BODY_SIZE 8
/** @brief Serialized size of FrameHeader. */
#define FRAME_HEADER_SIZE 6