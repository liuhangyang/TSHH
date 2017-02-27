//
// Created by yang on 16-8-5.
//

#ifndef TSHH_ROLLCALL_H
#define TSHH_ROLLCALL_H
#include "../model/RollCall.hpp"
#include "../dao/RollCallDAO.h"
#include <list>
class RollCallSrv {
public:
    RollCallSrv() = default;
    ~RollCallSrv() = default;

    int add(RollCall rollCall);

    int delet(std::string condition);

    int update(RollCall rollCall);

    std::list<RollCall> inquire(std::string condition);

private:
    RollCallDAO *rollCallDAO = new RollCallDAO();
};


#endif //TSHH_ROLLCALL_H
