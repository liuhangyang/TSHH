//
// Created by yang on 16-8-5.
//

#include "DatadSrv.h"
#include "../model/Datad.hpp"
#include <list>

int DatadSrv::add(Datad datad)
{
    return datadDAO->insert(datad);
}

int DatadSrv::delet(std::string condition)
{
    return datadDAO->dele(condition);
}

int DatadSrv::update(Datad datad)
{
    return datadDAO->updat(datad);
}

std::list<Datad> DatadSrv::inquire(std::string condition)
{
    return datadDAO->find(condition);
}