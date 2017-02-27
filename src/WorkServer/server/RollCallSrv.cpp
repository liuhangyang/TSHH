//
// Created by yang on 16-8-5.
//

#include "RollCallSrv.h"
#include "../model/RollCall.hpp"
#include <list>

int RollCallSrv::add(RollCall rollCall)
{
    return rollCallDAO->insert(rollCall);
}

int RollCallSrv::delet(std::string condition)
{
    return rollCallDAO->dele(condition);
}

int RollCallSrv::update(RollCall rollCall)
{
    return rollCallDAO->updat(rollCall);
}

std::list<RollCall> RollCallSrv::inquire(std::string condition)
{
    return rollCallDAO->find(condition);
}
