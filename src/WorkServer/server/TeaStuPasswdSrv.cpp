//
// Created by yang on 16-8-5.
//

#include "TeaStuPasswdSrv.h"
#include "../model/TeaStuPasswd.hpp"
#include <list>

int TeaStuPasswdSrv::add(TeaStuPasswd teaStuPasswd)
{
    return teaStuPasswdDAO->insert(teaStuPasswd);
}
int TeaStuPasswdSrv::delet(std::string condition)
{
    return teaStuPasswdDAO->dele(condition);
}
int TeaStuPasswdSrv::update(TeaStuPasswd teaStuPasswd)
{
    return teaStuPasswdDAO->updat(teaStuPasswd);
}
std::list<TeaStuPasswd> TeaStuPasswdSrv::inquire(std::string condition)
{
    return teaStuPasswdDAO->find(condition);
}
