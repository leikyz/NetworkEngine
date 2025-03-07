﻿#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include "ClientManager.h"
#include <winsock2.h> 
#include "Message.h"
#pragma comment(lib, "Ws2_32.lib")

#define PORT 5555
#define BUFFER_SIZE 1024

class Server
{
private:
    static SOCKET serverSocket; 

public:
    static void Start();
    static void Send(sockaddr_in clientAddr, Message& message);
};

#endif // SERVER_H
