#pragma once
#include "Buffer.h"
#include "HttpResponse.h"
#include <functional>
#include <map>

// 当前的解析状态
enum class PrecessState : char
{
    ParseReqLine,
    ParseReqHeaders,
    ParseReqBody,
    ParseReqDone
};
// 定义http请求结构体
class HttpRequest
{
public:
    HttpRequest();
    ~HttpRequest();
    // 重置
    void reset();
    // 添加请求头
    void addHeader(const std::string key, const std::string value);
    // 根据key得到请求头的value
    std::string getHeader(const std::string key);
    // 解析请求行
    bool ParseRequestLine(Buffer *readBuf);
    // 解析请求头
    bool parseRequestHeader(Buffer *readBuf);
    // 解析http请求协议
    bool parseHttpRequest(Buffer *readBuf, HttpResponse *response, Buffer *sendBuf, int socket);
    // 处理http请求协议
    bool processHttpRequest(HttpResponse *response);
    // 解码字符串
    std::string decodeMsg(std::string from);
    const std::string getFileType(const std::string name);
    static void sendDir(std::string dirName, Buffer *sendBuf, int cfd);
    static void sendFile(std::string fileName, Buffer *sendBuf, int cfd);
    inline void SetMethod(std::string method)
    {
        m_method = method;
    }
    inline void SetUrl(std::string url)
    {
        m_url = url;
    }
    inline void SetVersion(std::string version)
    {
        m_version = version;
    }
    // 获取处理状态
    inline PrecessState GetState()
    {
        return m_curState;
    }
    inline void SetState(PrecessState state)
    {
        m_curState = state;
    }

private:
    int hexToDec(char c);
    int SplitRequestLine(const std::string &str, const char *sub, int pos, std::function<void(std::string)> callback);

private:
    std::string m_method;
    std::string m_url;
    std::string m_version;
    std::map<std::string, std::string> m_reqHeaders;
    PrecessState m_curState;
};
