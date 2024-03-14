#pragma once
#include "EventLoop.h"
#include "Channel.h"
#include <string>
class EventLoop;
class Dispatcher
{
protected:
    std::string c_Name = std::string();
    Channel *c_channel;
    EventLoop *c_evLoop;

public:
    Dispatcher(EventLoop *evLoop);
    virtual ~Dispatcher();
    // 添加事件
    virtual int Add();
    // 删除事件
    virtual int Delete();
    // 修改事件
    virtual int Modify();
    // 事件检测
    virtual int DispatcherEvent(int timeout = 2);
    inline void SetChannel(Channel *channel)
    {
        c_channel = channel;
    }
};
