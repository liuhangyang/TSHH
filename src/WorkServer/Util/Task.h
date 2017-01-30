//
// Created by yang on 16-8-15.
//

#ifndef TSHH_TASK_H
#define TSHH_TASK_H

#include<string>
class Task {
public:
    Task()= default;
    ~Task()= default;
    Task(int fd,int type,std::string);
     void doTask();
    int fd;
    int type;
    std::string Str;
    void do_task(Task &task);
};


#endif //TSHH_TASK_H
