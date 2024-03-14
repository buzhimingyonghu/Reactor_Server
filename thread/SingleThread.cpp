#include "SingleThread.h"
SingleThread::SingleThread(int index)
{
    c_evLoop = nullptr;
    c_thread = nullptr;
    c_threadID = std::thread::id();
    c_name = "SingleThread_" + std::to_string(index);
}

SingleThread::~SingleThread()
{
    if (c_thread != nullptr)
    {
        delete c_thread;
        delete c_evLoop;
    }
}

void SingleThread::run()
{
    c_thread = new std::thread(&SingleThread::running, this);
    std::unique_lock<std::mutex> locker(c_mutex);
    while (c_evLoop == nullptr)
    {
        c_cond.wait(locker);
    }
}

void SingleThread::running()
{
    c_mutex.lock();
    c_evLoop = new EventLoop(c_name);
    c_mutex.unlock();
    c_cond.notify_one();
    c_evLoop->run();
}
