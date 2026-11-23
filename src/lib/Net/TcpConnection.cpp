    #include "TcpConnection.h"

    // TODO: Implement TCP connection operations.
    TcpConnection::TcpConnection() : socketHandle(INVALID_SOCKET) {}
    TcpConnection::~TcpConnection() {}
    bool TcpConnection::Connect(const char* host, uint16_t port) { (void)host; (void)port; return false; }
    bool TcpConnection::SendAll(const uint8_t* buffer, uint32_t length) { (void)buffer; (void)length; return false; }
    bool TcpConnection::RecvAll(uint8_t* buffer, uint32_t length) { (void)buffer; (void)length; return false; }
    void TcpConnection::Close() {}