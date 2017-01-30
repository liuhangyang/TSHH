//
// Created by kiosk on 8/15/16.
//

#ifndef _OBJECTTOJSON_HPP
#define _OBJECTTOJSON_HPP

#include <string>
#include <iostream>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>

class objectToJson {
public:
    objectToJson() = default;
    ~objectToJson() = default;

    int getlength(int sock_fd,epoll_event (&events)[100],int eventsSequence,int epollfd) {
        int i;
        char fir_buf[4];
        bzero(fir_buf, 4);
         //printf("read\n");
        if ((i = recv(sock_fd, fir_buf, 4,0)) == 0) {
            std::cout << "recv error" << std::endl;
            epoll_event ev;
            ev.data.fd = sock_fd;
            epoll_ctl(epollfd,EPOLL_CTL_DEL,sock_fd,&ev);
            close(sock_fd);
        } else {
//            printf(">>>>>");
//            for (int i = 0; i < 4; ++i) {
//                printf("%d ", fir_buf[i]);
//            }
//            printf(">>>>>\n");
            int a = (int) (fir_buf[0] & 0x7f);
            int b = (int) (fir_buf[1] & 0x7f) * 128;
            int c = (int) (fir_buf[2] & 0x7f) * 16384;
            int d = (int) (fir_buf[3] & 0x7f) * 2097152;
            return a+b+c+d;
        }

        return 0;
    }

    int getType(int sock_fd,epoll_event (&events)[100],int eventsSequence,int epollfd) {
    
        int i;
        char fir_buf[4];
        bzero(fir_buf, 4);
        if ((i = recv(sock_fd, fir_buf, 4, 0)) == 0) {
            std::cout << "recv error" << std::endl;
            epoll_event ev;
            ev.data.fd = sock_fd;
            epoll_ctl(epollfd,EPOLL_CTL_DEL,sock_fd,&ev);
            close(sock_fd);
        } else {
//            printf(">>>>>");
//            for (int i = 0; i < 4; ++i) {
//                printf("%d ", fir_buf[i]);
//            }
//            printf(">>>>>\n");
            int a = (int) (fir_buf[0] & 0x7f);
            int b = (int) (fir_buf[1] & 0x7f) * 128;
            int c = (int) (fir_buf[2] & 0x7f) * 16384;
            int d = (int) (fir_buf[3] & 0x7f) * 2097152;
            return a+b+c+d;
        }

        return 0;
    }

    std::string getJson(int sock_fd,epoll_event (&events)[100],int eventsSequence,int epollfd,int length) {
        int i;
        char fir_buf[length];
        bzero(fir_buf, length);
        if ((i = recv(sock_fd, fir_buf, length, 0)) == 0) {
            std::cout << "recv error" << std::endl;
            epoll_event ev;
            ev.data.fd = sock_fd;
            epoll_ctl(epollfd,EPOLL_CTL_DEL,sock_fd,&ev);
            close(sock_fd);
        } else {
            std::string json(fir_buf);
            //std::cout << "json::"<<std::endl;
            return json;
        }
        return NULL;
    }

};

#endif
