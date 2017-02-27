//
// Created by yang on 16-8-5.
//

#ifndef TSHH_BIGCLASS_H
#define TSHH_BIGCLASS_H

#include "../model/BigClass.hpp"
#include "../dao/BigClassDAO.h"
#include <list>

class BigClassSrv {
public:
    int add(BigClass bigClass);    /*添加ansWer*/

    int delet(std::string condition);   /*删除符合条件的数据*/

    int update(BigClass bigClass);     /*根据主键修改整行数据*/

    std::list<BigClass> inquire(std::string condition);     /*根据condition条件查询数据*/

private:
    BigClassDAO  *bigClassDAO = new BigClassDAO();
};


#endif //TSHH_BIGCLASS_H
