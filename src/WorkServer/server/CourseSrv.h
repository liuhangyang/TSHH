//
// Created by yang on 16-8-5.
//

#ifndef TSHH_COURSE_H
#define TSHH_COURSE_H

#include "../model/Course.hpp"
#include "../dao/CourseDAO.h"
#include <list>

class CourseSrv {
public:
    CourseSrv() = default;
    ~CourseSrv() = default;
    int add(Course course);
    int delet(std::string condition);
    int update(Course course);
    std::list<Course> inquire(std::string condition);

private:
    CourseDAO *courseDAO = new CourseDAO();
};


#endif //TSHH_COURSE_H
