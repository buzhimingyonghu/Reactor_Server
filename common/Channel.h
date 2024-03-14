#pragma once
#include <functional>

// 问题1 作用是什么
enum class FDevent
{
    ReadEvent = 0x02,
    WriteEvent = 0x04
};

class Channel
{
private:
    int c_fd;
    // 问题2 能否修改成FDevent类型
    int c_event;
    void *c_arg;

public:
    using backFunc = std::function<int(void *)>;
    Channel(int fd, FDevent event, backFunc readFunc, backFunc writeFunc, backFunc destroyFunc, void *arg);
    ~Channel();
    void WriteEventEnable(bool flag);
    bool IsWriteEventEnable();
    backFunc readCallBack;
    backFunc writeCallBack;
    backFunc destroyCallBack;
    inline int GetFd()
    {
        return c_fd;
    }
    inline int GetEvent()
    {
        return c_event;
    }
    inline const void *GetArg()
    {
        return c_arg;
    }
};
