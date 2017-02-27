//
// Created by yang on 16-8-5.
//

#include "ScheduleCourseSrv.h"
#include "../model/ScheduleCourse.hpp"
#include <list>

int ScheduleCourseSrv::delet(std::string condition)
{
    return scheduleCourseDAO->dele(condition);
}
int ScheduleCourseSrv::update(ScheduleCourse scheduleCourse)
{
    return scheduleCourseDAO->updat();
}
std::list<ScheduleCourse> ScheduleCourseSrv::inquire(std::string condition)
{}