//
// Created by yang on 16-8-5.
//

#include "BigClassListSrv.h"
#include "../model/BigClassList.hpp"

int BigClassListSrv::add(BigClassList bigClassList)
{
    return bigClassListDAO->insert(bigClassList);
}

int BigClassListSrv::delet(std::string condition)
{
    return bigClassListDAO->dele(condition);
}

int BigClassListSrv::updat(BigClassList bigClassList)
{
    return bigClassListDAO->updat(bigClassList);
}

std::list<BigClassList> BigClassListSrv::inquire(std::string condition)
{
    return bigClassListDAO->find(condition);
}