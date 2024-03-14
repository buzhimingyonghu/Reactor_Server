#pragma once
#include "EventLoop.h"
#include "ThreadPool.h"
#include "Channel.h"
#include <string>
class TcpServer
{
public:
    TcpServer(int port, int threadNum);
    ~TcpServer();
    int run();
    int setListen();
    int acceptConnection();

private:
    ThreadPool *c_pool;
    EventLoop *c_mainLoop;
    Channel *c_channel;
    int c_lfd;
    int c_threadNum;
    int c_port;
};