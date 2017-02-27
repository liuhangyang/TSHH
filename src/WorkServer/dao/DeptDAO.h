//
// Created by yang on 16-8-4.
//

#ifndef TSHH_DEPTDAO_H
#define TSHH_DEPTDAO_H

#include "../model/Dept.hpp"
#include <list>

class DeptDAO {
    int insert(Dept dept);
    int dele(std::string condition);
    int updat(Dept dept);
    std::list<Dept> find(std::string condition);
};


#endif //TSHH_DEPTDAO_H
