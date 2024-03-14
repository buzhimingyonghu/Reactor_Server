#pragma once
#include "EventLoop.h"
#include "Dispatcher.h"
#include <sys/epoll.h>
class EpollDispatcher : public Dispatcher
{
private:
    int c_epfd;
    struct epoll_event *c_events;
    // epoll_event的个数
    const int c_maxNode = 520;

public:
    EpollDispatcher(EventLoop *evLoop);
    ~EpollDispatcher();
    int Add() override;
    int Delete() override;
    int Modify() override;
    int DispatcherEvent(int timeout = 2) override;

private:
    int epollCtl(int op);
};
