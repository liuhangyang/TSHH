//
// Created by kiosk on 8/9/16.
//

#ifndef TSHH_BALANCE_BALANCE_SERVER_H
#define TSHH_BALANCE_BALANCE_SERVER_H

#include <sys/epoll.h>
#include <netinet/in.h>
#include <string>
#include <vector>
#include <memory>

#define EPOLL_SIZE 1024
#define BACKLOG    1024
#define PORT       7777

class balance_server {
public:
    void init();
    void func(int,std::string,int);

private:
    int thread_size = 0;
    int num = 0;

    //std::shared_ptr<int>  listen_fds = nullptr;
    int *listen_fds = nullptr;
    //std::shared_ptr<int>  epoll_fds = nullptr;
    int *epoll_fds = nullptr;
    //std::shared_ptr<std::shared_ptr<epoll_event>>  evss = nullptr;
    struct epoll_event **evss = nullptr;
    std::vector<std::string>  worker_ip;
    std::vector<int>          worker_port;
};


#endif //TSHH_BALANCE_BALANCE_SERVER_H
