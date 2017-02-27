//
// Created by yang on 16-8-5.
//

#ifndef TSHH_DATAD_H
#define TSHH_DATAD_H

#include "../model/Datad.hpp"
#include "../dao/DatadDAO.h"

class DatadSrv {
public:
    DatadSrv() = default;
    ~DatadSrv() = default;

    int add(Datad datad);
    int delet(std::string condition);
    int update(Datad datad);
    std::string inquire(Datad datad);

private:
    DatadDAO *datadDAO = new DatadDAO();
};


#endif //TSHH_DATAD_H
