//
// Created by yang on 16-8-5.
//

#include "CourseSrv.h"
#include "../model/Course.hpp"
#include "../dao/CourseDAO.h"

int CourseSrv::add(Course course)
{
    return courseDAO->insert(course);
}

int CourseSrv::delet(std::string condition)
{
    return courseDAO->dele(condition);
}

int CourseSrv::update(Course course)
{
    return courseDAO->updat(course);
}

std::list<Course> CourseSrv::inquire(std::string condition)
{
    return courseDAO->find(condition);
}