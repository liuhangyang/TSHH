//
// Created by yang on 16-8-4.
//

#ifndef TSHH_DATADDAO_H
#define TSHH_DATADDAO_H

#include "../model/Datad.hpp"
#include <list>

class DatadDAO {
public:
    int insert(Datad datad);
    int dele(std::string condition);
    int updat(Datad datad);
    std::list<Datad> find(std::string condition);
};


#endif //TSHH_DATADDAO_H
