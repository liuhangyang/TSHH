//
// Created by yang on 16-8-9.
//

#include "server.h"
#include <iostream>
#include <thread>
server::server(int server_s,int connfd_num) {
    epoll_num=server_s;
    connfd_num=connfd_num;
}
void 
server::server_work(int fd){
    Epoll epoll(fd);
    epoll.startPool();
    epoll.Epoll_loop();
}
bool
server::server_start() {
    Socket getSocket(AF_INET,connfd_num);
    sockfd=getSocket.return_fd();
    std::thread threads[3];
    for(int i=0;i<epoll_num;i++){
        threads[i]=std::thread(server_work,sockfd);
    }
    for(int i=0;i<epoll_num;i++){
        threads[i].join();
    }
    return true;
}
