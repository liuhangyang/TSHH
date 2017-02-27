//
// Created by yang on 16-8-5.
//

#ifndef TSHH_TEACHERPLAN_H
#define TSHH_TEACHERPLAN_H

#include "../model/TeacherPlan.hpp"
#include "../dao/TeacherPlanDAO.h"
#include <list>

class TeacherPlanSrv {
public:
    TeacherPlanSrv();
    ~TeacherPlanSrv();

    int add(TeacherPlan teacherPlan);
    int delet(std::string condition);
    int update(TeacherPlan teacherPlan);
    std::list<TeacherPlan> inquire(std::string condition);

private:
    TeacherPlanDAO *teacherPlanDAO = new TeacherPlanDAO();
};


#endif //TSHH_TEACHERPLAN_H
