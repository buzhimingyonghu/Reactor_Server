#include "TcpConnection.h"
#include "Log.h"
TcpConnection::TcpConnection(int cfd, EventLoop *evLoop)
{
    c_evLoop = evLoop;
    c_readBuf = new Buffer;
    c_writeBuf = new Buffer;
    c_request = new HttpRequest;
    c_response = new HttpResponse;
    c_name = "Connection_" + std::to_string(cfd);
    c_channel = new Channel(cfd, FDevent::ReadEvent, ProcessRead, ProcessWrite, Destroy, this);
    c_evLoop->AddTask(ElemType::ADD, c_channel);
}

TcpConnection::~TcpConnection()
{
    delete c_readBuf;
    delete c_writeBuf;
    delete c_request;
    delete c_response;
    c_evLoop->FreeChannel(c_channel);
    Debug("连接断开, 释放资源, gameover, connName: %s", c_name.data());
}

int TcpConnection::ProcessRead(void *arg)
{
    TcpConnection *conn = static_cast<TcpConnection *>(arg);
    int cfd = conn->c_channel->GetFd();
    int count = conn->c_readBuf->socketRead(cfd);
    Debug("接受到http请求: %s", conn->c_readBuf->data());
    if (count > 0)
    {
        bool flag=conn->c_request->parseHttpRequest(conn->c_readBuf,conn->c_response,conn->c_writeBuf,cfd);
        if(!flag)
        {
           std::string errMsg="Http/1.1 400 Bad Request\r\n\r\n";
           conn->c_writeBuf->appendString(errMsg);
        }
    }
    conn->c_evLoop->AddTask(ElemType::DELETE,conn->c_channel);
    return 0;
}

int TcpConnection::ProcessWrite(void *arg)
{
    Debug("开始发送数据了(基于写事件发送)....");
    TcpConnection*conn=static_cast<TcpConnection*>(arg);
    int count=conn->c_writeBuf->sendData(conn->c_channel->GetFd());
    if(count>0)
    {
        if(conn->c_writeBuf->readableSize()==0)
        {
            conn->c_channel->WriteEventEnable(false);
            conn->c_evLoop->AddTask(ElemType::DELETE,conn->c_channel);

        }
    }
    return 0;
}

int TcpConnection::Destroy(void *arg)
{
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    if (conn != nullptr)
    {
        delete conn;
    }
    return 0;
}
