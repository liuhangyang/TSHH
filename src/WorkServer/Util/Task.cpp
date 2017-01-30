//
// Created by yang on 16-8-15.
//

#include "Task.h"
#include<string>
#include<vector>
#include<sys/types.h>
#include<sys/socket.h>
#include "SyncQueue.hpp"
#include "jsonTomap.hpp"
#include <unordered_map>
#include "StringToJson.hpp"
#include "Login.hpp"
Task::Task(int fd, int type, std::string Str) {
    this->fd=fd;
    this->type=type;
    this->Str=Str;
}
 void
Task::do_task(Task &task){
        std::unordered_map<std::string,std::vector<std::string>> acceptmap;
        jsonTomap myjson(task.Str);
        acceptmap=myjson.getMap(); //得到保存账号密码的map.
        switch(task.type){
            case 0:{
            std::string username=acceptmap["ts_name"][0];
            std::string passwd=acceptmap["ts_passwd_content"][0];
            Login login(username,passwd);
                std::unordered_map<std::string,std::string> s=login.getstuinfo();
                for(auto b:s){
                    std::cout << b.first << " : "<<b.second<<std::endl;
                }
                if(s["st"]=="200"){ 
                std::unordered_map<std::string,std::vector<std::string>> acceptmap1;
                std::vector<std::string> p;
                p.push_back("1");
                acceptmap1["status"]=p;
                StringToJson json(task.type,acceptmap1);
                std::string str=json.ObjectToJson();
                send(task.fd,str.c_str(),str.size(),0);
                }else{
                    
                    std::unordered_map<std::string,std::vector<std::string>> acceptmap1;
                    std::vector<std::string> p;
                    p.push_back(s["st"]);
                    acceptmap1["status"]=p;
                    p={};
                    p.push_back(s["value"]);
                    acceptmap1["value"]=p;
                    StringToJson json(task.type,acceptmap1);
                    std::string str=json.ObjectToJson();
                    send(task.fd,str.c_str(),str.size(),0);
                }
            }//登录请求.
            break;
            case 1:
            break;
            default:
            break;
        }
    }
