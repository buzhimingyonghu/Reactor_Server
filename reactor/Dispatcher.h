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
    virtual ~Dispatcher() = 0;
    // 添加事件
    virtual int Add() = 0;
    // 删除事件
    virtual int Delete() = 0;
    // 修改事件
    virtual int Modify() = 0;
    // 事件检测
    virtual int DispatcherEvent(int timeout = 2) = 0;
    inline void SetChannel(Channel *channel)
    {
        c_channel = channel;
    }
};
