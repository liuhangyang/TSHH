//
// Created by yang on 16-8-5.


#include "SingleClassSrv.h"
#include "../model/SingleClass.hpp"
#include <list>

int SingleClassSrv::add(SingleClass singleClass)
{
    return singleClassDAO->insert(singleClass);
}
int SingleClassSrv::delet(std::string condition)
{
    return singleClassDAO->dele(condition);
}
int SingleClassSrv::update(SingleClass singleClass)
{
    return singleClassDAO->updat(singleClass);
}
std::list<SingleClass> SingleClassSrv::inquire(std::string condition)
{
    return singleClassDAO->find(condition);
}