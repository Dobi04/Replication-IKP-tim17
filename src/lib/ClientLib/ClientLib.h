#pragma once

#ifdef SendMessage
#undef SendMessage   // Windows makro bi inače preimenovao našu funkciju
#endif

/** @brief Connect to the queue identified by queueName. */
bool Connect(const char* queueName);
/** @brief Send a message with the specified size. */
bool SendMessage(const void* message, int messageSize);
/** @brief Retrieve all stored messages from the other replicator. */
bool GetMessages(void** outMessages, int* outCount);