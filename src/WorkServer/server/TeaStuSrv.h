//
// Created by yang on 16-8-5.
//

#ifndef TSHH_TEASTU_H
#define TSHH_TEASTU_H
#include "../model/TeaStu.hpp"
#include "../dao/TeaStuDAO.h"
#include <list>

class TeaStuSrv {
public:
    TeaStuSrv() = default;
    ~TeaStuSrv() = default;
    int add(TeaStu teaStu);
    int delet(std::string condition);
    int update(TeaStu teaStu);
    std::list<TeaStu> inquire(std::string condition);

private:
    TeaStuDAO *teaStuDAO = new TeaStuDAO();
};


#endif //TSHH_TEASTU_H
