#include "Buffer.h"
#include <string.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
Buffer::Buffer()
{
}

Buffer::~Buffer()
{
}

int Buffer::appendString(const char *data)
{
    int size = strlen(data);
    int ret = appendString(data, size);
    return ret;
}
int Buffer::appendString(const char *data, int n)
{
    if (n >= 0)
        m_data.append(data, n);
    return 0;
}
int Buffer::appendString(const std::string &data)
{
    return appendString(data, data.size());
}
int Buffer::appendString(const std::string &data, int n)
{
    if (n == 0 || data.size() == 0)
    {
        return -1;
    }
    m_data.append(data, n);
    return 0;
}
int Buffer::socketRead(int fd)
{
    struct iovec vec[2];
    char *temp1 = (char *)malloc(40960);
    vec[0].iov_base = temp1;
    vec[0].iov_len = 40960;
    char *temp2 = (char *)malloc(40960);
    vec[1].iov_base = temp2;
    vec[1].iov_len = 40960;
    int ret = readv(fd, vec, 2);
    if (ret == -1)
    {
        return -1;
    }
    else
    {
        appendString(temp1, ret <= 40960 ? ret : 40960);
        if (ret >= 40960)
        {
            appendString(temp2, ret - 40960);
        }
    }
    free(temp1);
    free(temp2);
    return ret;
}

int Buffer::findStr(const char *str)
{
    return findStr(m_readPos, str);
}
int Buffer::findStr(int pos, const char *str)
{
    return m_data.find(str, pos);
}
int Buffer::findStr(const std::string &str)
{
    return findStr(m_readPos, str);
}
int Buffer::findStr(int pos, const std::string &str)
{
    return m_data.find(str, pos);
}
int Buffer::readPosIncrease(int count)
{
    int maxLen = 10240;
    m_readPos += count;
    if (m_readPos >= maxLen)
    {
        m_data.erase(0, m_readPos);
        m_readPos = 0;
    }
    return 0;
}

int Buffer::sendData(int socket)
{
    // 判断有无数据
    int readable = readableSize();
    if (readable > 0)
    {
        int count = send(socket, &m_data[m_readPos], readable, MSG_NOSIGNAL);
        if (count > 0)
        {
            readPosIncrease(count);
            usleep(1);
        }
        return count;
    }
    return 0;
}
