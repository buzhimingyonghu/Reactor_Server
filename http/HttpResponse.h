#pragma once
#include <functional>
#include "Buffer.h"
#include <map>
enum class Statuscode
{
    UnKnown,
    OK = 200,
    MovedPermanently = 301,
    MovedTemporarily = 302,
    BadRequest = 400,
    NotFound = 404
};
class HttpResponse
{
private:
    Statuscode m_statusCode;
    std::string m_fileName;
    std::map<std::string, std::string> m_headers;
    const std::map<int, std::string> m_info = {
        {200, "OK"},
        {301, "MovedPermanently"},
        {302, "MovedTemporarily"},
        {400, "BadRequest"},
        {404, "NotFound"},
    };

public:
    HttpResponse();
    ~HttpResponse();
    std::function<void(const std::string, Buffer *, int)> sendDataFunc;
    void Addheader(const std::string key, const std::string value);
    void PrepareMsg(Buffer *sendBuf, int socket);
    inline void SetFileName(std::string name)
    {
        m_fileName = name;
    }
    inline void SetStatusCode(Statuscode code)
    {
        m_statusCode = code;
    }
};
