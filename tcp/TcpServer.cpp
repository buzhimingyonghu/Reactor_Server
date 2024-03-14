#include "TcpServer.h"
#include "TcpConnection.h"
#include "Log.h"
#include <arpa/inet.h>
#include <stdio.h>
TcpServer::TcpServer(int port, int threadNum)
{
    c_port = port;
    c_mainLoop = new EventLoop;
    c_threadNum = 0;
    c_pool = new ThreadPool(c_mainLoop, c_threadNum);
    c_lfd = 0;
    setListen();
}
int TcpServer::run()
{
    Debug("server start...");

    c_pool->run();
    c_mainLoop->AddTask(ElemType::ADD, c_channel);
    c_mainLoop->run();

    return 0;
}
int TcpServer::setListen()
{

    c_lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (c_lfd == -1)
    {
        perror("socket");
        return -1;
    }
    int opt = 1;
    int ret = setsockopt(c_lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt);
    if (ret == -1)
    {
        perror("setsocketopt");
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(c_port);
    addr.sin_addr.s_addr = INADDR_ANY;
    ret = bind(c_lfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind");
    }
    ret = listen(c_lfd, 128);
    if (ret == -1)
    {
        perror("listen");
        return -1;
    }
    // 质疑1
    auto func = std::bind(&TcpServer::acceptConnection, this);
    c_channel = new Channel(c_lfd, FDevent::ReadEvent, func, nullptr, nullptr, nullptr);
    return 0;
}
int TcpServer::acceptConnection()
{
    int cfd = accept(c_lfd, NULL, NULL);
    EventLoop *evLoop = c_pool->takeWorkerLoop();
    // 问题1需不要创建变量存储
    new TcpConnection(cfd, evLoop);
    return 0;
}
