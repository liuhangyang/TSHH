//
// Created by yang on 16-8-5.
//

#include "ClassroomSrv.h"
#include "../model/Classroom.hpp"
#include <list>

int add(Classroom classroom)
{
    return ClassroomDAO->insert(classroom);
}

int delet(std::string condition)
{
    return ClassroomDAO->dele(condition);
}

int update(Classroom classroom)
{
    return updat(classroom);
}

std::list<Classroom> inquire(std::string condition)
{
    return find(condition);
}