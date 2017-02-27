//
// Created by yang on 16-8-5.
//

#ifndef TSHH_BIGCLASSLIST_H
#define TSHH_BIGCLASSLIST_H

#include "../model/BigClassList.hpp"
#include "../dao/BigClassListDAO.h"
#include <list>

class BigClassListSrv {
public:
    BigClassListSrv() = default;
    ~BigClassListSrv() = default;

    int add(BigClassList bigClassList);

    int delet(std::string condition);

    int update(BigClassList bigClassList);

    std::list<BigClassList> inquire(std::string condition);
private:
    BigClassListDAO  *bigClassListDAO = new BigClassListDAO();
};

#endif //TSHH_BIGCLASSLIST_H
