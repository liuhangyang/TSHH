//
// Created by kiosk on 8/9/16.
//

#include <iostream>
#include <sys/socket.h>
#include <queue>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include <fstream>
#include <unistd.h>

#include "balance_server.h"
#include "error.h"
#include "common.hpp"


void balance_server::init()
{
    int  listen_fd;                           //socket返回
    int  epoll_fd;                            //epoll_create 返回
    int  conn_fd;                             //accept返回
    int  nfds;                                //epoll_wait 返回
    socklen_t  conn_len;
    struct sockaddr_in serv_addr,conn_addr;
    struct epoll_event ev, evs[EPOLL_SIZE];
    char send_buf[1024],recv_buf[1024];

    error myerror;
    std::ifstream input("/home/kiosk/Desktop/TSHH_Balance/resource/worker_server.conf");
    if(input) {
        std::string line;
        std::getline(input,line);
        thread_size = atoi(line.c_str());    //初始化线程的数量

        while (std::getline(input,line)) {
            worker_ip.push_back(line);        //将IP放入
            std::getline(input,line);
            worker_port.push_back(atoi(line.c_str()));   //将port放入
        }
    }

    //申请相应的空间
    //listen_fds = std::make_shared<int>(thread_size);
    //epoll_fds = std::make_shared<int>(thread_size);
    //evss =  std::make_shared<std::shared_ptr<epoll_event>>(thread_size);
    listen_fds = (int *)malloc(sizeof(int)*thread_size);
    epoll_fds = (int *)malloc(sizeof(int) * thread_size);
    evss = (struct epoll_event **)malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

    for (int i = 0; i < thread_size; ++i) {
        std::shared_ptr<std::thread> t = std::make_shared<std::thread>(&balance_server::func,this,i,worker_ip.back(),worker_port.back());
        t->detach();
        //std::cout << worker_ip.back() << std::endl;
        worker_ip.pop_back();
        //std::cout << worker_port.back() << std::endl;
        worker_port.pop_back();
    }

    if((listen_fd = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        myerror.set("socket",__LINE__).show();
    }


    int option_value = 1;
    int length = sizeof(option_value);
    setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&option_value,length);

    memset(&serv_addr,0,sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listen_fd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr_in)) == -1) {
        myerror.set("bind",__LINE__).show();
    }


    if(listen(listen_fd,BACKLOG) == -1) {
        myerror.set("listen",__LINE__).show();
    }

    if((epoll_fd = epoll_create(EPOLL_SIZE)) == -1) {
        myerror.set("epoll_create",__LINE__).show();
    }

    ev.data.fd = listen_fd;
    ev.events = EPOLLIN;
    if(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,listen_fd,&ev) == -1) {
        myerror.set("epoll_ctl",__LINE__).show();
    }

    conn_len = sizeof(struct sockaddr_in);

    std::cout << "主服务器启动..." << std::endl;

    while(1) {
        nfds = epoll_wait(epoll_fd,evs,EPOLL_SIZE,10);
        sleep(1);
        std::cout << "main thread nfds : " << nfds << std::endl;
        for(int i = 0;i < nfds;++i) {
            if(evs[i].data.fd == listen_fd) {
                conn_fd = accept(listen_fd,(struct sockaddr *)&conn_addr,&conn_len);
                std::cout << "accept a new connection : "<<inet_ntoa(conn_addr.sin_addr) << "分配fd:  " << conn_fd << std::endl;
                ev.data.fd = conn_fd;
                ev.events = EPOLLIN;

                if(num == thread_size) {
                    num = 0;
                }
                std::cout << "num is : " << num << std::endl;
                if(epoll_ctl(epoll_fds[num],EPOLL_CTL_ADD,conn_fd,&ev) == -1) {
                    myerror.set("epoll_ctl",__LINE__).show();
                }
                num++;

            }else if(evs[i].events &  EPOLLIN) {
                std::cout << "\n push EPOLLIN \n" <<std::endl;
                bzero(recv_buf,1024);
                recv(listen_fd,recv_buf,1024,0);

                std::cout << recv_buf << std::endl;
                send(listen_fd,recv_buf,1024,0);

            }else if (evs[i].events & EPOLLOUT) {
                std::cout << "\n push EPOLLOUT \n" <<std::endl;
            }
        }
    }
}

void balance_server::func(int thread_num,std::string ip,int port)
{
    std::cout << thread_num << " " << ip << " " << port << " " << std::endl;
    struct sockaddr_in serv_addr,serv_addr1,conn_addr;
    struct epoll_event ev,evs[EPOLL_SIZE];
    error myerror;
    int conn_len,nfds;
    int listen_fd1;

    char send_buf[1024],recv_buf[1024];

    if((listen_fds[thread_num] = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        myerror.set("socket",__LINE__).show();
    }
    if((listen_fd1 = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        myerror.set("socket",__LINE__).show();
    }

    std::cout << "thread " << thread_num << " fd : " << listen_fds[thread_num] << std::endl;

    int option_value = 1;
    int length = sizeof(option_value);
    setsockopt(listen_fds[thread_num],SOL_SOCKET,SO_REUSEADDR,&option_value,length);

    memset(&serv_addr,0,sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listen_fds[thread_num],(struct sockaddr *)&serv_addr,sizeof(struct sockaddr_in)) == -1) {
        myerror.set("bind",__LINE__).show();
    }


    if(listen(listen_fds[thread_num],BACKLOG) == -1) {
        myerror.set("listen",__LINE__).show();

    }

    memset(&serv_addr1,0,sizeof(struct sockaddr_in));
    serv_addr1.sin_family = AF_INET;
    serv_addr1.sin_port = htons(8888);
    inet_aton(ip.c_str(),(struct in_addr *)&serv_addr1.sin_addr);

    if(connect(listen_fd1,(struct sockaddr *)&serv_addr1,sizeof(struct sockaddr_in)) == -1) {
        std::cout << thread_num << std::endl;
        myerror.set("connect",__LINE__).show();
    }


    if((epoll_fds[thread_num] = epoll_create(EPOLL_SIZE)) == -1) {
        myerror.set("epoll_create",__LINE__).show();
    }

    ev.data.fd = listen_fd1;
    ev.events = EPOLLIN;
    if(epoll_ctl(epoll_fds[thread_num],EPOLL_CTL_ADD,listen_fd1,&ev) == -1) {
        myerror.set("epoll_ctl",__LINE__).show();
    }

    ev.data.fd = listen_fds[thread_num];
    ev.events = EPOLLIN;
    if(epoll_ctl(epoll_fds[thread_num],EPOLL_CTL_ADD,listen_fds[thread_num],&ev) == -1) {
        myerror.set("epoll_ctl",__LINE__).show();
    }

    conn_len = sizeof(struct sockaddr_in);

    std::cout << "服务器 "<< thread_num << " 启动..." << std::endl;

    while(1) {
        if((nfds = epoll_wait(epoll_fds[thread_num],evs,EPOLL_SIZE,10)) == -1) {
            myerror.set("epoll_wait",__LINE__).show();
        }
        sleep(1);
        for(int i = 0;i < nfds;++i) {
            if(evs[i].data.fd == listen_fds[thread_num]) {
                /*conn_fd = accept(listen_fd,(struct sockaddr *)&conn_addr,&conn_len);
                std::cout << "accept a new connection : "<<inet_ntoa(conn_addr.sin_addr) << " fenpei: " << conn_fd << std::endl;
                ev.data.fd = conn_fd;
                ev.events = EPOLLIN | EPOLLOUT | EPOLLET;
                MessageQueue.push(ev);
                if(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,conn_fd,&ev) == -1) {
                    myerror.set("epoll_ctl",__LINE__).show();
                }*/
            }else if(evs[i].events &  EPOLLIN) {
                std::cout << "\n push EPOLLIN \n" <<std::endl;
                bzero(recv_buf,1024);
                if(recv(evs[i].data.fd,recv_buf,1024,0) <= 0) {
                    myerror.set("read",__LINE__).show();
                }

                std::cout << recv_buf << std::endl;
                send(listen_fd1,recv_buf,1024,0);

            }else if (evs[i].events & EPOLLOUT) {
                std::cout << "\n push EPOLLOUT \n" <<std::endl;

            }
        }
    }
}