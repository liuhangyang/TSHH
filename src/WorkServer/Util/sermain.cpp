/*************************************************************************
	> File Name: sermain.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年08月10日 星期三 20时21分24秒
 ************************************************************************/

#include<iostream>
#include "server.h"
using namespace std;
int main(int argc,char *argv[])
{
    server myserver(3,10);
    myserver.server_start();
   return 0;
}
