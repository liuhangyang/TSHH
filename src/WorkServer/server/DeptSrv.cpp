//
// Created by yang on 16-8-5.
//

#include "DeptSrv.h"
#include "../model/Dept.hpp"

int DeptSrv::add(Dept dept)
{
    return DeptDAO->insert(dept);
}

int DeptSrv::delet(std::string condition)
{
    return DeptDAO->dele(condition);
}

int DeptSrv::update(Dept dept)
{
    return DeptDAO->updat(dept);
}

std::list<Dept> DeptSrv::inquire(std::string condition)
{
    return DeptDAO->find(condition);
}