    #include "TcpListener.h"

    // TODO: Implement listening and accepting TCP sockets.
    TcpListener::TcpListener() : socketHandle(INVALID_SOCKET) {}
    TcpListener::~TcpListener() {}
    bool TcpListener::Listen(uint16_t port) { (void)port; return false; }
    SOCKET TcpListener::Accept() { return INVALID_SOCKET; }
    void TcpListener::Close() {}