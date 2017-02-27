//
// Created by yang on 16-8-5.
//

#ifndef TSHH_DOWNLOAD_H
#define TSHH_DOWNLOAD_H

#include "../model/DownLoad.hpp"
#include "../dao/DownLoadDAO.h"

class DownLoadSrv {
public:
    DownLoadSrv() = default;
    ~DownLoadSrv() = default;
    int add(DownLoad downLoad);
    int delet(std::string condition);
    int update(DownLoad downLoad);
    std::list<DownLoad> inquire(std::string condition);
private:
    DownLoadDAO *downLoadDAO = new DownLoadDAO();
};


#endif //TSHH_DOWNLOAD_H
