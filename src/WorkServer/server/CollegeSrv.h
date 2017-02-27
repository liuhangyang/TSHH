//
// Created by yang on 16-8-5.
//

#ifndef TSHH_COLLEGE_H
#define TSHH_COLLEGE_H

#include "../model/College.hpp"
#include "../dao/CollegeDAO.h"
#include <list>

class CollegeSrv {
public:
    CollegeSrv() = default;
    ~CollegeSrv() = default;
    int add(College college);
    int delet(std::string condition);
    int update(College college);
    std::list<College> inquire(std::string condition);

private:
    CollegeDAO *collegeDAO = new CollegeDAO;
};


#endif //TSHH_COLLEGE_H
