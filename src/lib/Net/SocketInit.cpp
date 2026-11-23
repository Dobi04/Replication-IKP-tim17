    #include "SocketInit.h"

    // TODO: Initialize and clean up Winsock.
    SocketInit::SocketInit() : initialized(false) {}
    SocketInit::~SocketInit() {}
    bool SocketInit::IsInitialized() const { return initialized; }