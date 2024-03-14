#pragma once
#include <string>
#include <iostream>
class Buffer
{
private:
    std::string m_data;
    int m_readPos = 0;

public:
    Buffer();
    ~Buffer();

    int appendString(const char *data);
    int appendString(const char *data, int n);
    int appendString(const std::string &data);
    int appendString(const std::string &data, int n);
    int findStr(int pos, const std::string &str);
    int findStr(const std::string &str);
    int findStr(const char *str);
    int findStr(int pos, const char *str);

    int readPosIncrease(int count);
    int socketRead(int fd);
    int sendData(int socket);

    inline int readableSize()
    {
        return m_data.size() - m_readPos;
    }
    inline const char *data()
    {
        return &m_data[m_readPos];
    }
    inline std::string GetSubstr(int pos, int n)
    {
        return m_data.substr(pos, n);
    }
    inline int GetReadPos()
    {
        return m_readPos;
    }
    inline int Npos()
    {
        return m_data.size();
    }
};