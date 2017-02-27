//
// Created by yang on 16-8-5.
//

#include "BigClassSrv.h"
#include "../model/BigClass.hpp"


int add(BigClass bigClass)
{
    return insert(bigClass);
}

int delet(std::string condition)
{
    return dele(condition);
}

int update(BigClass bigClass)
{
    return updat(bigClass);
}

std::list<BigClass> inquire(std::string condition)
{
    return find(condition);
}
