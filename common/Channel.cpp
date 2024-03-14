#include "Channel.h"

Channel::Channel(int fd, FDevent event, backFunc readFunc, backFunc writeFunc, backFunc destroyFunc, void *arg)
{
    c_fd = fd;
    c_event = static_cast<int>(event);
    c_arg = arg;
    readCallBack = readFunc;
    writeCallBack = writeFunc;
    destroyCallBack = destroyFunc;
}

Channel::~Channel()
{
}

void Channel::WriteEventEnable(bool flag)
{
    if(flag)
    {
        c_event|=static_cast<int>(FDevent::WriteEvent);
    }else{

        c_event|=~static_cast<int>(FDevent::WriteEvent);
    }
}

bool Channel::IsWriteEventEnable()
{
    return c_event&static_cast<int>(FDevent::WriteEvent);
}
