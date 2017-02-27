//
// Created by yang on 16-8-5.
//

#ifndef TSHH_DEPT_H
#define TSHH_DEPT_H
#include "../model/Dept.hpp"
#include "../dao/DeptDAO.h"

class DeptSrv {
public:
    DeptSrv() = default;
    ~DeptSrv() = default;

    int add(Dept dept);
    int delet(std::string condition);
    int update(Dept dept);
    std::list<Dept> inquire(std::string condition);

private:
    DeptDAO *deptDAO = new DeptDAO();
};


#endif //TSHH_DEPT_H
