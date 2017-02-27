//
// Created by yang on 16-8-5.
//

#include "CollegeSrv.h"
#include "../model/College.hpp"
#include "../dao/CollegeDAO.h"
#include <list>

int  CollegeSrv::add(College college)
{
    return CollegeDAO->insert(college);
}

int CollegeSrv::delet(std::string condition)
{
    return CollegeDAO->dele(condition);
}
int CollegeSrv::update(College college)
{
    return CollegeDAO->updat(college);
}
std::list<College> CollegeSrv::inquire(std::string condition)
{
    return CollegeDAO->find(condition);
}
