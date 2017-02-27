//
// Created by yang on 16-8-4.
//

#ifndef TSHH_SINGLECLASSDAO_H
#define TSHH_SINGLECLASSDAO_H
#include "../model/SingleClass.hpp"
#include <list>

class SingleClassDAO {
    int insert(SingleClass singleClass);
    int dele(std::string condition);
    int updat(SingleClass singleClass);
    std::list<SingleClass> find(std::string condition);
};


#endif //TSHH_SINGLECLASSDAO_H
