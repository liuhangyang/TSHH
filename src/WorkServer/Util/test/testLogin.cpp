/*************************************************************************
	> File Name: testLogin.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年08月23日 星期二 17时52分11秒
 ************************************************************************/

#include<iostream>
#include "Login.hpp"
#include<unordered_map>
using namespace std;
int main(int argc,char *argv[])
{
    Login login("04143162","Y18220744696");
    std::unordered_map<std::string,std::string> s=login.getstuinfo();
    for(auto t:s){
        std::cout << t.first << " : "<<t.second<<std::endl;

    }
   return 0;
}
