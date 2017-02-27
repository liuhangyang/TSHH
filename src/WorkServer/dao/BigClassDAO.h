//
// Created by yang on 16-8-4.
//

#ifndef TSHH_BIGCLASSDAO_H
#define TSHH_BIGCLASSDAO_H

#include "../model/BigClass.hpp"
#include <list>

class BigClassDAO {
public:
    int insert(BigClass bigClass);
    int add(BigClass bigClass);    /*添加*/

    int delet(std::string condition);   /*删除符合条件的数据*/

    int update(BigClass bigClass);     /*根据主键修改整行数据*/

    std::list<BigClass> find(std::string condition);   /*根据condition条件查询数据*/
};


#endif //TSHH_BIGCLASSDAO_H
