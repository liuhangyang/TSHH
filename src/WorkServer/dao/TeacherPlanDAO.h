//
// Created by yang on 16-8-4.
//

#ifndef TSHH_TEACHERPLANDAO_H
#define TSHH_TEACHERPLANDAO_H
#include "../model/TeacherPlan.hpp"
#include <list>

class TeacherPlanDAO {

    int insert(TeacherPlan teacherPlan);
    int dele(std::string condition);
    int updat(TeacherPlan teacherPlan);
    std::list<TeacherPlan> find(std::string condition);
};


#endif //TSHH_TEACHERPLANDAO_H
