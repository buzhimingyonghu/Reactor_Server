#include "ThreadPool.h"
#include <assert.h>
ThreadPool::ThreadPool(EventLoop *mainLoop, int threadNum)
{
    c_mainLoop = mainLoop;
    c_threadNum = threadNum;
    c_isStart = false;
    c_index = 0;
    c_singleThreads.clear();
}

ThreadPool::~ThreadPool()
{
    for (auto it : c_singleThreads)
    {
        delete it;
    }
}

int ThreadPool::run()
{
    assert(!c_isStart);
    if (c_mainLoop->GetThreadId() != std::this_thread::get_id())
    {
        exit(0);
    }
    c_isStart = true;
    for (int i = 0; i < c_threadNum; i++)
    {
        SingleThread *temp_Thread = new SingleThread(i);
        temp_Thread->run();
        c_singleThreads.push_back(temp_Thread);
    }
    return 0;
}

EventLoop *ThreadPool::takeWorkerLoop()
{
    assert(c_isStart);
    if (c_mainLoop->GetThreadId() != std::this_thread::get_id())
    {
        exit(0);
    }
    EventLoop *evLoop = c_mainLoop;
    if (c_threadNum > 0)
    {
        evLoop = c_singleThreads[c_index]->GetEventLoop();
        c_index = ++c_index % c_threadNum;
    }
    return evLoop;
}
