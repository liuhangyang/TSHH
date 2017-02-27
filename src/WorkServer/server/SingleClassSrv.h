//
// Created by yang on 16-8-5.
//

#ifndef TSHH_SINAGLECLASS_H
#define TSHH_SINAGLECLASS_H

#include "../model/SingleClass.hpp"
#include "../dao/SingleClassDAO.h"
#include <list>
class SingleClassSrv {
public:
    SingleClassSrv() = default;
    ~SingleClassSrv() = default;

    int add(SingleClass singleClass);

    int delet(std::string condition);

    int update(SingleClass singleClass);

    std::list<SingleClass> inquire(std::string condition);

private:
    SingleClassDAO *singleClassDAO = new SingleClassDAO();
};


#endif //TSHH_SINAGLECLASS_H
