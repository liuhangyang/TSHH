//
// Created by yang on 16-8-4.
//

#ifndef TSHH_COURSEDAO_H
#define TSHH_COURSEDAO_H

#include "../model/Course.hpp"
#include <list>

class CourseDAO {
public:
    int insert(Course course);
    int dele(std::string condition);
    int updat(Course course);
    std::list<Course> find(std::string condition);
};


#endif //TSHH_COURSEDAO_H
