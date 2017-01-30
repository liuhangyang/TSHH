//
// Created by yang on 16-8-5.
//

#ifndef TSHH_TEASTUPASSWD_H
#define TSHH_TEASTUPASSWD_H

#include "../model/TeaStuPasswd.hpp"
#include "../dao/TeaStuPasswdDAO.h"
#include <list>

class TeaStuPasswdSrv {
public:
    TeaStuPasswdSrv() = default;
    ~TeaStuPasswdSrv() = default;
    int add(TeaStuPasswd teaStuPasswd);
    int delet(std::string condition);
    int update(TeaStuPasswd teaStuPasswd);
    std::list<TeaStuPasswd> inquire(std::string condition);

private:
    TeaStuPasswdDAO *teaStuPasswdDAO = new TeaStuPasswdDAO();
};


#endif //TSHH_TEASTUPASSWD_H
