//
// Created by yang on 16-8-5.
//

#ifndef TSHH_SCHEDULECOURSE_H
#define TSHH_SCHEDULECOURSE_H

#include "../model/ScheduleCourse.hpp"
#include "../dao/ScheduleCourseDAO.h"
#include <list>

class ScheduleCourseSrv {
public:
    ScheduleCourse() = default;
    ~ScheduleCourse() = default;
    int add(ScheduleCourse scheduleCourse);
    int delet(std::string condition);
    int update(ScheduleCourse scheduleCourse);
    std::list<ScheduleCourse> inquire(std::string condition);

private:
    ScheduleCourseDAO *scheduleCourseDAO = new ScheduleCourseDAO();
};


#endif //TSHH_SCHEDULECOURSE_H
