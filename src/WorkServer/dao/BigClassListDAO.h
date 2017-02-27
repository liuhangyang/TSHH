//
// Created by yang on 16-8-4.
//

#ifndef TSHH_BIGCLASSLISTDAO_H
#define TSHH_BIGCLASSLISTDAO_H

#include "../model/BigClassList.hpp"
#include <list>
#include <string>
class BigClassListDAO {
public:
    int insert(BigClassList bigClassList);
    int delet(std::string condition);
    int updat(BigClassList bigClassList);
    std::list<BigClassList> find(std::string condition);
};

#endif //TSHH_BIGCLASSLISTDAO_H
