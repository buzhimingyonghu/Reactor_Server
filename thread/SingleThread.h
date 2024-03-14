#pragma once
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include "EventLoop.h"
class SingleThread
{
private:
    EventLoop *c_evLoop;
    std::string c_name;
    std::thread *c_thread;
    std::thread::id c_threadID;
    std::mutex c_mutex;
    std::condition_variable c_cond;

public:
    SingleThread(int index);
    ~SingleThread();
    void run();
    inline EventLoop *GetEventLoop()
    {
        return c_evLoop;
    }

private:
    void running();
};
