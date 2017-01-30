//
// Created by yang on 16-8-4.
//

#ifndef TSHH_TEASTUDAO_H
#define TSHH_TEASTUDAO_H

#include "../model/TeaStu.hpp"

class TeaStuDAO {
public:
    int insert(TeaStu teaStu);
    int dele(std::string condition);
    int updat(TeaStu teaStu);
    std::list<TeaStu> find(std::string condition);
};


#endif //TSHH_TEASTUDAO_H
