    #include "FrameIO.h"

    // TODO: Implement framed TCP reads and writes.
    bool WriteFrame(TcpConnection* connection, uint8_t type, const uint8_t* body, uint32_t bodyLength)
    {
        (void)connection; (void)type; (void)body; (void)bodyLength;
        return false;
    }

    bool ReadFrame(TcpConnection* connection, FrameHeader* header, uint8_t* bodyBuffer, uint32_t bufferCapacity)
    {
        (void)connection; (void)header; (void)bodyBuffer; (void)bufferCapacity;
        return false;
    }