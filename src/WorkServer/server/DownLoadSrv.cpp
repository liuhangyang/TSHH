//
// Created by yang on 16-8-5.
//

#include "DownLoadSrv.h"
#include "../model/DownLoad.hpp"
#include <list>

int DownLoadSrv::add(DownLoad downLoad)
{
    return DownLoadDAO->insert(downLoad);
}
int DownLoadSrv::delet(std::string condition)
{
    return DownLoadDAO->dele(condition);
}
int DownLoadSrv::update(DownLoad downLoad)
{
    return DownLoadDAO->updat(downLoad);
}
std::list<DownLoad> DownLoadSrv::inquire(std::string condition)
{
    return DownLoadDAO->find(condition);
}