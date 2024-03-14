#pragma once
#include "EventLoop.h"
#include "Buffer.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Channel.h"
class TcpConnection
{
private:
    std::string c_name;
    EventLoop *c_evLoop;
    Channel *c_channel;
    HttpRequest *c_request;
    HttpResponse *c_response;
    Buffer *c_readBuf;
    Buffer *c_writeBuf;

public:
    TcpConnection(int cfd, EventLoop *evLoop);
    ~TcpConnection();
    static int ProcessRead(void *arg);
    static int ProcessWrite(void *arg);
    static int Destroy(void *arg);
};
