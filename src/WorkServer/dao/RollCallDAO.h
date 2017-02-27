//
// Created by yang on 16-8-4.
//

#ifndef TSHH_ROLLCALLDAO_H
#define TSHH_ROLLCALLDAO_H
#include "../model/RollCall.hpp"
#include <list>

class RollCallDAO {
public:
    int insert(RollCall rollCall);
    int dele(std::string condition);
    int updat(RollCall rollCall);
    std::list<RollCall> find(std::string condition);
};


#endif //TSHH_ROLLCALLDAO_H
