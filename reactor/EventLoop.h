#pragma once
#include "Dispatcher.h"
#include "Channel.h"
#include <queue>
#include <map>
#include <thread>
#include <mutex>
#include <string>
enum class ElemType : char
{
    ADD,
    DELETE,
    MODIFY
};
class Dispatcher;
using ChannelNode = std::pair<ElemType, Channel *>;
class EventLoop
{
private:
    bool c_isQuit;
    // 该指针指向子类的实例 epoll, poll, select
    Dispatcher *c_dispatcher;
    // 任务队列
    std::queue<ChannelNode> c_taskQue;
    // channelmap
    std::map<int, Channel *> c_channelMap;
    std::thread::id c_threadId;
    std::mutex c_mutex;
    std::string c_threadName;
    int c_socketPair[2];

public:
    EventLoop(std::string threadName = std::string());
    ~EventLoop();
    int run();
    // 添加任务到任务队列
    int AddTask(ElemType type, Channel *channel);
    // 处理激活的文件描述符FD
    int EventActive(int fd, int event);
    // 处理任务队列中任务
    int ProcessTaskQ();
    // 处理dispatcher中的节点
    int Add(Channel *channel);
    int Delete(Channel *channel);
    int Modify(Channel *channel);
    // 释放channel
    int FreeChannel(Channel *channel);
    int ReadMessage();

    inline std::thread::id GetThreadId()
    {
        return c_threadId;
    }
    inline std::string GetThreadName()
    {
        return c_threadName;
    }

private:
    void TaskWakeup();
};
