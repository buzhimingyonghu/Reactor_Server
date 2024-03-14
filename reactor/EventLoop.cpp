#include "EventLoop.h"
#include "EpollDispatcher.h"
#include <assert.h>
#include <arpa/inet.h>
#include <string.h>
#include "unistd.h"
EventLoop::EventLoop(std::string threadName)
{
    c_isQuit = true;
    c_threadId = std::this_thread::get_id();
    c_threadName = threadName == std::string() ? "mainLoop" : threadName;
    c_dispatcher = new EpollDispatcher(this);
    int ret = socketpair(AF_UNIX, SOCK_STREAM, 0, c_socketPair);
    if (ret == -1)
    {
        perror("socketpair");
        exit(0);
    }
    auto obj = std::bind(&EventLoop::ReadMessage, this);
    Channel *channel = new Channel(c_socketPair[1], FDevent::ReadEvent, obj, nullptr, nullptr, this);
    AddTask(ElemType::ADD, channel);
}

EventLoop::~EventLoop()
{
}
int EventLoop::run()
{
    c_isQuit = false;
    if (c_threadId != std::this_thread::get_id())
    {
        return -1;
    }
    while (!c_isQuit)
    {
        c_dispatcher->DispatcherEvent();
        ProcessTaskQ();
    }
    return 0;
}

int EventLoop::AddTask(ElemType type, Channel *channel)
{
    c_mutex.lock();
    c_taskQue.push({type, channel});
    c_mutex.unlock();
    if (c_threadId == std::this_thread::get_id())
    {
        ProcessTaskQ();
    }
    else
    {
        TaskWakeup();
    }
    return 0;
}

int EventLoop::EventActive(int fd, int event)
{
    if (fd < 0)
    {
        return -1;
    }
    Channel *channel = c_channelMap[fd];
    assert(channel->GetFd() == fd);
    if (event & static_cast<int>(FDevent::ReadEvent) && channel->readCallBack)
    {
        channel->readCallBack(const_cast<void *>(channel->GetArg()));
    }
    if (event & static_cast<int>(FDevent::WriteEvent) && channel->writeCallBack)
    {
        channel->writeCallBack(const_cast<void *>(channel->GetArg()));
    }
    return 0;
}

int EventLoop::ProcessTaskQ()
{
    while (!c_taskQue.empty())
    {
        c_mutex.lock();
        ChannelNode node = c_taskQue.front();
        c_taskQue.pop();
        c_mutex.unlock();
        Channel *channel = node.second;
        if (node.first == ElemType::ADD)
        {
            Add(channel);
        }
        else if (node.first == ElemType::DELETE)
        {
            Delete(channel);
        }
        else if (node.first == ElemType::MODIFY)
        {
            Modify(channel);
        }
    }
    return 0;
}

int EventLoop::Add(Channel *channel)
{
    int fd = channel->GetFd();
    if (c_channelMap.find(fd) == c_channelMap.end())
    {
        c_channelMap.insert(std::make_pair(fd, channel));
        c_dispatcher->SetChannel(channel);
        int ret = c_dispatcher->Add();
        return ret;
    }
    return -1;
}

int EventLoop::Delete(Channel *channel)
{
    int fd = channel->GetFd();
    if (c_channelMap.find(fd) == c_channelMap.end())
    {
        return -1;
    }
    c_dispatcher->SetChannel(channel);
    int ret = c_dispatcher->Delete();
    return ret;
}

int EventLoop::Modify(Channel *channel)
{
    int fd = channel->GetFd();
    if (c_channelMap.find(fd) == c_channelMap.end())
    {
        return -1;
    }
    c_dispatcher->SetChannel(channel);
    int ret = c_dispatcher->Modify();
    return ret;
}

int EventLoop::FreeChannel(Channel *channel)
{
    auto it = c_channelMap.find(channel->GetFd());
    if (it != c_channelMap.end())
    {
        c_channelMap.erase(it);
        close(channel->GetFd());
        delete (channel);
    }
    return 0;
}

int EventLoop::ReadMessage()
{
    char buff[256];
    read(c_socketPair[1], buff, sizeof(buff));
    return 0;
}

void EventLoop::TaskWakeup()
{
    const char *msg = "该起来了!!!";
    write(c_socketPair[0], msg, strlen(msg));
}
