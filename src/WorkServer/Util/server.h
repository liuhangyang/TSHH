//
// Created by yang on 16-8-9.
//

#ifndef TSHH_SERVER_H
#define TSHH_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <string>
#include <sys/syscall.h>

#include "Epoll.h"
#include "Accept.h"
#include "Socket.h"
class server {
public:
    server(int server_s,int connfd_num);
  bool server_start();

   static void server_work(int fd);
private:
    int epoll_num;  /*epoll的个数*/
    int sockfd;
    int connfd_num;  /*监听最大连接数*/

};


#endif //TSHH_SERVER_H
