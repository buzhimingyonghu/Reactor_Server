#include <iostream>
#include <unistd.h>
#include "TcpServer.h"
int main(int argc, char *argv[])
{
    // if (argc < 3)
    // {
    //     std::cout << "please enter port and IPaddress" << std::endl;
    // }
    unsigned short port = 10000;
    chdir("/home/nlove/server");
    TcpServer *tcp = new TcpServer(port, 4);
    tcp->run();
}