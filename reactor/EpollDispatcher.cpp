#include "EpollDispatcher.h"
EpollDispatcher::EpollDispatcher(EventLoop *evLoop) : Dispatcher(evLoop)
{
    c_epfd = epoll_create(10);
    if (c_epfd == -1)
    {
        perror("epoll_create");
        exit(0);
    }
    c_events = new struct epoll_event[c_maxNode];
    c_Name = "Epoll";
}

EpollDispatcher::~EpollDispatcher()
{
}

int EpollDispatcher::Add()
{
    int ret = epollCtl(EPOLL_CTL_ADD);
    if (ret == -1)
    {
        perror("epoll_ctl_add");
        return -1;
    }
    return ret;
}

int EpollDispatcher::Delete()
{
    int ret = epollCtl(EPOLL_CTL_DEL);
    if (ret == -1)
    {
        perror("epoll_ctl_del");
        return -1;
    }
    // 问题1
    c_channel->destroyCallBack(const_cast<void *>(c_channel->GetArg()));
    return ret;
}

int EpollDispatcher::Modify()
{
    int ret = epollCtl(EPOLL_CTL_MOD);
    if (ret == -1)
    {
        perror("epoll_crl modify");
        exit(0);
    }
    return ret;
}

int EpollDispatcher::DispatcherEvent(int timeout)
{
    int count = epoll_wait(c_epfd, c_events, c_maxNode, timeout * 1000);
    for (int i = 0; i < count; i++)
    {
        int events = c_events[i].events;
        int fd = c_events[i].data.fd;
        if (events & EPOLLERR || events & EPOLLHUP)
        {
            // 对方断开了连接
            continue;
        }
        if (events == EPOLLIN)
        {
            c_evLoop->EventActive(fd, static_cast<int>(FDevent::ReadEvent));
        }
        if (events == EPOLLOUT)
        {
            c_evLoop->EventActive(fd, static_cast<int>(FDevent::WriteEvent));
        }
    }
    return 0;
}

int EpollDispatcher::epollCtl(int op)
{
    struct epoll_event ev;
    ev.data.fd = c_channel->GetFd();
    int events = 0;
    if (c_channel->GetEvent() & static_cast<int>(FDevent::ReadEvent))
    {
        events |= EPOLLIN;
    }
    if (c_channel->GetEvent() & static_cast<int>(FDevent::WriteEvent))
    {
        events |= EPOLLOUT;
    }
    ev.events = events;
    int ret = epoll_ctl(c_epfd, op, c_channel->GetFd(), &ev);
    return ret;
}
