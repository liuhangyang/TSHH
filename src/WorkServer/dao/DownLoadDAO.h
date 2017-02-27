//
// Created by yang on 16-8-4.
//

#ifndef TSHH_DOWNLOADDAO_H
#define TSHH_DOWNLOADDAO_H
#include "../model/DownLoad.hpp"
#include <list>

class DownLoadDAO {

    int insert(DownLoad downLoad);

    int dele(std::string condition);

    int updat(DownLoad downLoad);

    std::list<DownLoad> find(std::string condition);
};


#endif //TSHH_DOWNLOADDAO_H
