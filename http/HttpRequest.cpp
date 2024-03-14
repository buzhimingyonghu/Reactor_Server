#include "HttpRequest.h"
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cassert>
HttpRequest::HttpRequest()
{
    reset();
}

HttpRequest::~HttpRequest()
{
}

void HttpRequest::reset()
{
    m_curState = PrecessState::ParseReqLine;
    m_method = m_url = m_version = std::string();
    m_reqHeaders.clear();
}

void HttpRequest::addHeader(const std::string key, const std::string value)
{
    if (key.empty() || value.empty())
    {
        return;
    }
    m_reqHeaders.insert(std::make_pair(key, value));
}

std::string HttpRequest::getHeader(const std::string key)
{
    auto it = m_reqHeaders.find(key);
    if (it != m_reqHeaders.end())
    {
        return it->second;
    }
    return std::string();
}

int HttpRequest::SplitRequestLine(const std::string &str, const char *sub, int pos, std::function<void(std::string)> callback)
{
    int idx = str.find(sub, pos);
    if (idx != std::string::npos)
    {
        callback(str.substr(pos, idx - pos));
        return idx + strlen(sub);
    }
    return pos;
}

bool HttpRequest::ParseRequestLine(Buffer *readBuf)
{
    int end = readBuf->findStr("\r\n");
    if(end>=readBuf->Npos())
    return false;
    int start = readBuf->GetReadPos();
    int linesize = end - start;
    std::string line = readBuf->GetSubstr(start, linesize);
    if (!line.empty())
    {
        auto methodFunc = bind(&HttpRequest::SetMethod, this, std::placeholders::_1);
        start = SplitRequestLine(line, " ", start, methodFunc);
        auto urlFunc = bind(&HttpRequest::SetUrl, this, std::placeholders::_1);
        start = SplitRequestLine(line, " ", start, urlFunc);
        SetVersion(line.substr(start, line.size() - start));
        readBuf->readPosIncrease(linesize + 2);
        SetState(PrecessState::ParseReqHeaders);
        return true;
    }
    return false;
}

bool HttpRequest::parseRequestHeader(Buffer *readBuf)
{
    int end = readBuf->findStr("\r\n");
    if(end>=readBuf->Npos())
    return false;
    int start = readBuf->GetReadPos();
    int linesize = end - start;
    std::string line = readBuf->GetSubstr(start, linesize);
        int mid = line.find(": ", 0);
        if (mid != std::string::npos)
        {
            addHeader(line.substr(0, mid), line.substr(mid + 2, end - mid - 2));
            readBuf->readPosIncrease(linesize + 2);
        }
        else
        {
            readBuf->readPosIncrease(2);
            SetState(PrecessState::ParseReqDone);
        }
        return true;
    

    return false;
}

bool HttpRequest::parseHttpRequest(Buffer *readBuf, HttpResponse *response, Buffer *sendBuf, int socket)
{
    bool flag = true;
    while (m_curState != PrecessState::ParseReqDone)
    {
        switch (m_curState)
        {
        case PrecessState::ParseReqLine:
            flag = ParseRequestLine(readBuf);
            break;
        case PrecessState::ParseReqHeaders:
            flag = parseRequestHeader(readBuf);
            break;
        case PrecessState::ParseReqBody:
            break;
        default:
            break;
        }
        if (!flag)
        {
            return flag;
        }
        if (m_curState == PrecessState::ParseReqDone)
        {
            processHttpRequest(response);
            response->PrepareMsg(sendBuf, socket);
        }
    }
    m_curState = PrecessState::ParseReqLine;
    return true;
}

bool HttpRequest::processHttpRequest(HttpResponse *response)
{
    if (strcasecmp(m_method.data(), "get") != 0)
    {
        return false;
    }
    m_url = decodeMsg(m_url);
    const char *file = nullptr;
    if (strcmp(m_url.data(), "/") == 0)
    {
        file = "./";
    }
    else
    {
        file = m_url.data() + 1;
    }
    struct stat st;
    int ret = stat(file, &st);
    if (ret == -1)
    {
        response->SetFileName("404.html");
        response->SetStatusCode(Statuscode::NotFound);
        response->Addheader("Content-type", getFileType(".html"));
        response->sendDataFunc = sendFile;
        return true;
    }
    response->SetFileName(file);
    response->SetStatusCode(Statuscode::OK);
    if (S_ISDIR(st.st_mode))
    {
        response->Addheader("Content-type", getFileType(".html"));
        response->sendDataFunc = sendDir;
    }
    else
    {
        response->Addheader("Content-type", getFileType(file));
        response->Addheader("Content-length", std::to_string(st.st_size));
        response->sendDataFunc = sendFile;
    }
    return true;
}

std::string HttpRequest::decodeMsg(std::string from)
{
    std::string str = std::string();
    for (int i = 0; i < from.size(); i++)
    {
        if (from[i] == '%' && isxdigit(from[i + 1]) && isxdigit(from[i + 2]))
        {
            str.append(1, hexToDec(from[i + 1]) * 16 + hexToDec(from[i + 2]));
            i += 2;
        }
        else
        {
            str.append(1, from[i]);
        }
    }
    str.append(1, '\0');
    return str;
}
const std::string HttpRequest::getFileType(const std::string name)
{
    const char *dot = strrchr(name.data(), '.');
    if (dot == NULL)
        return "text/plain; charset=utf-8"; // 纯文本
    if (strcmp(dot, ".html") == 0 || strcmp(dot, ".htm") == 0)
        return "text/html; charset=utf-8";
    if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0)
        return "image/jpeg";
    if (strcmp(dot, ".gif") == 0)
        return "image/gif";
    if (strcmp(dot, ".png") == 0)
        return "image/png";
    if (strcmp(dot, ".css") == 0)
        return "text/css";
    if (strcmp(dot, ".au") == 0)
        return "audio/basic";
    if (strcmp(dot, ".wav") == 0)
        return "audio/wav";
    if (strcmp(dot, ".avi") == 0)
        return "video/x-msvideo";
    if (strcmp(dot, ".mov") == 0 || strcmp(dot, ".qt") == 0)
        return "video/quicktime";
    if (strcmp(dot, ".mpeg") == 0 || strcmp(dot, ".mpe") == 0)
        return "video/mpeg";
    if (strcmp(dot, ".vrml") == 0 || strcmp(dot, ".wrl") == 0)
        return "model/vrml";
    if (strcmp(dot, ".midi") == 0 || strcmp(dot, ".mid") == 0)
        return "audio/midi";
    if (strcmp(dot, ".mp3") == 0)
        return "audio/mpeg";
    if (strcmp(dot, ".ogg") == 0)
        return "application/ogg";
    if (strcmp(dot, ".pac") == 0)
        return "application/x-ns-proxy-autoconfig";

    return "text/plain; charset=utf-8";
}
void HttpRequest::sendDir(std::string dirName, Buffer *sendBuf, int cfd)
{
    char buff[4096] = {0};
    sprintf(buff, "<html><head><title>%s</title></head><body><table>", dirName.data());
    struct dirent **nameList;
    int num = scandir(dirName.data(), &nameList, NULL, alphasort);
    for (int i = 0; i < num; i++)
    {
        char *name = nameList[i]->d_name;
        struct stat st;
        char subpath[1024] = {0};
        sprintf(subpath, "%s/%s", dirName.data(), name);
        stat(subpath, &st);
        if (S_ISDIR(st.st_mode))
        {
            sprintf(buff + strlen(buff), "<tr><td><a href=\"%s/\">%s</a></td><td>%ld</td></tr>",
                    name, name, st.st_size);
        }
        else
        {
            sprintf(buff + strlen(buff), "<tr><td><a href=\"%s\">%s</a></td><td>%ld</td></tr>",
                    name, name, st.st_size);
        }
        sendBuf->appendString(buff, strlen(buff));
        sendBuf->sendData(cfd);
        memset(buff, 0, sizeof(buff));
        free(nameList[i]);
    }
    sprintf(buff, "</table></body></html>");
    sendBuf->appendString(buff);
    sendBuf->sendData(cfd);
    free(nameList);
}
void HttpRequest::sendFile(std::string fileName, Buffer *sendBuf, int cfd)
{
    int fd = open(fileName.data(), O_RDONLY);
    assert(fd > 0);
    while (1)
    {
        char buff[1024];
        int len = read(fd, buff, sizeof buff);
        if (len > 0)
        {
            sendBuf->appendString(buff, len);
            sendBuf->sendData(cfd);
        }
        else if (len == 0)
        {
            break;
        }
        else
        {
            close(fd);
            perror("read");
        }
    }
    close(fd);
}
int HttpRequest::hexToDec(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }
    return 0;
}