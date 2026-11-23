    #include "ClientLib.h"

    // TODO: Implement the public client library interface.
    bool Connect(char* queueName) { (void)queueName; return false; }
    bool SendMessage(void* message, int messageSize) { (void)message; (void)messageSize; return false; }
    bool GetMessages(/* TODO: add output parameters for received messages */) { return false; }