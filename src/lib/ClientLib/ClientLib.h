#pragma once

/** @brief Connect to the queue identified by queueName. */
bool Connect(char* queueName);
/** @brief Send a message with the specified size. */
bool SendMessage(void* message, int messageSize);
/** @brief Retrieve messages; TODO: add output parameters for received messages. */
bool GetMessages(/* TODO: add output parameters for received messages */);