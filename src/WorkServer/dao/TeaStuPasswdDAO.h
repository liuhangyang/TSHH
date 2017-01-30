//
// Created by yang on 16-8-4.
//

#ifndef TSHH_TEASTUPASSWDDAO_H
#define TSHH_TEASTUPASSWDDAO_H

#include <list>
#include "../model/TeaStuPasswd.hpp"

class TeaStuPasswdDAO {
    int insert(TeaStuPasswd teaStuPasswd);
    int dele(std::string condition);
    int updat(TeaStuPasswd teaStuPasswd);
    std::list<TeaStuPasswd> find(std::string condition);
};


#endif //TSHH_TEASTUPASSWDDAO_H
