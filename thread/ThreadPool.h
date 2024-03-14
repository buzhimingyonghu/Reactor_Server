#pragma once
#include "EventLoop.h"
#include "SingleThread.h"
#include <vector>
class ThreadPool
{
private:
    EventLoop *c_mainLoop;
    bool c_isStart;
    int c_threadNum;
    std::vector<SingleThread *> c_singleThreads;
    int c_index;

public:
    ThreadPool(EventLoop *mainLoop, int threadNum);
    ~ThreadPool();
    int run();
    EventLoop *takeWorkerLoop();
};
