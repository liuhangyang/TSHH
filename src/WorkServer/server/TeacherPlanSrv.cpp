//
// Created by yang on 16-8-5.
//

#include "TeacherPlanSrv.h"
#include "../model/TeacherPlan.hpp"
#include <list>

int TeacherPlanSrv::add(TeacherPlan teacherPlan)
{
    return teacherPlanDAO->insert(teacherPlan);
}

int TeacherPlanSrv::delet(std::string condition)
{
    return teacherPlanDAO->dele(condition);
}

int TeacherPlanSrv::update(TeacherPlan teacherPlan)
{
    return teacherPlanDAO->updat(teacherPlan);
}

std::list<TeacherPlan> TeacherPlanSrv::inquire(std::string condition)
{
    return teacherPlanDAO->find(condition);
}