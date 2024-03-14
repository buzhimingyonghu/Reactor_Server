#include "HttpResponse.h"
#include <string.h>
HttpResponse::HttpResponse()
{
    m_statusCode = Statuscode::UnKnown;
    m_fileName = std::string();
    m_headers.clear();
    sendDataFunc = nullptr;
}
HttpResponse::~HttpResponse()
{
}

void HttpResponse::Addheader(const std::string key, const std::string value)
{
    if (key.empty() || value.empty())
    {
        return;
    }
    m_headers.insert(std::make_pair(key, value));
}
void HttpResponse::PrepareMsg(Buffer *sendBuf, int socket)
{
    char buf[4096] = {0};
    int code = static_cast<int>(m_statusCode);
    sprintf(buf, "HTTP/1.1 %d %s\r\n", code, m_info.at(code).data());
    sendBuf->appendString(buf);
    memset(buf, 0, sizeof(buf));
    for (auto &it : m_headers)
    {
        sprintf(buf + strlen(buf), "%s: %s\r\n", it.first.data(), it.second.data());
    }
    sendBuf->appendString(buf);
    sendBuf->appendString("\r\n");
    sendBuf->sendData(socket);
    sendDataFunc(m_fileName, sendBuf, socket);
}
