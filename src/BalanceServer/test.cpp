//
// Created by kiosk on 8/10/16.
//

//
// Created by kiosk on 8/10/16.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <zconf.h>

int main() {
    int flag = 0;
    int num = 0;

    while (1) {
    if(flag == 0) {
        num = 0;
        flag = 1;
    }else {
        num = 1;
        flag = 0;
    }
    std::cout << "num is : " << num << std::endl;
        sleep(1);
    }
//    int thread_size = 0;
//    std::vector<std::string>  worker_ip;
//    std::vector<int>          worker_port;
//    std::ifstream input("/home/kiosk/Desktop/TSHH_Balance/resource/worker_server.conf");
//    if(input) {
//        std::string line;
//        std::getline(input,line);
//        thread_size = atoi(line.c_str());    //初始化线程的数量
//
//        while (std::getline(input,line)) {
//            worker_ip.push_back(line);        //将IP放入
//            std::getline(input,line);
//            worker_port.push_back(atoi(line.c_str()));   //将port放入
//        }
//    }
//
//    std::cout << thread_size << std::endl;
////    for (auto it = worker_ip.begin(); it != worker_ip.end();++it) {
////        std::cout << *it << std::endl;
////        std::cout << worker_port.back() << std::endl;
////    }
//    for (int i = 0; i < thread_size; ++i) {
//        std::cout << worker_ip.back() << std::endl;
//        worker_ip.pop_back();
//        std::cout << worker_port.back() << std::endl;
//        worker_port.pop_back();
//    }
}
