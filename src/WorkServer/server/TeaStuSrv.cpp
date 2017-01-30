//
// Created by yang on 16-8-5.
//

#include "TeaStuSrv.h"
#include "../model/TeaStu.hpp"

int TeaStuSrv::add(TeaStu teaStu)
{
    return teaStuDAO->insert(teaStu);
}
int TeaStuSrv::delet(std::string condition)
{
    return teaStuDAO->dele(condition);
}
int TeaStuSrv::update(TeaStu teaStu)
{
    return teaStuDAO->updat(teaStu);
}
std::list<TeaStu> TeaStuSrv::inquire(std::string condition)
{
    return teaStuDAO->find(condition);
}

