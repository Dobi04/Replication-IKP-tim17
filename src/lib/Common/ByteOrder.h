#pragma once

#include <stdint.h>

/** @brief Write an unsigned 16-bit value in big-endian byte order. */
void WriteUint16Be(uint8_t* buffer, uint16_t value);
/** @brief Read an unsigned 16-bit value in big-endian byte order. */
uint16_t ReadUint16Be(const uint8_t* buffer);
/** @brief Write an unsigned 32-bit value in big-endian byte order. */
void WriteUint32Be(uint8_t* buffer, uint32_t value);
/** @brief Read an unsigned 32-bit value in big-endian byte order. */
uint32_t ReadUint32Be(const uint8_t* buffer);
/** @brief Write an unsigned 64-bit value in big-endian byte order. */
void WriteUint64Be(uint8_t* buffer, uint64_t value);
/** @brief Read an unsigned 64-bit value in big-endian byte order. */
uint64_t ReadUint64Be(const uint8_t* buffer);
/** @brief Write a 32-bit IEEE float in big-endian byte order. */
void WriteFloat32Be(uint8_t* buffer, float value);
/** @brief Read a 32-bit IEEE float in big-endian byte order. */
float ReadFloat32Be(const uint8_t* buffer);