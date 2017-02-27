//
// Created by yang on 16-8-5.
//

#ifndef TSHH_ANSWER_H
#define TSHH_ANSWER_H

#include "../model/AnsWer.hpp"
#include "../dao/AnsWerDAO.h"
#include <list>

class AnsWerSrv {

public:
    AnsWerSrv() = default;
    ~AnsWerSrv()  = default;

    int add(AnsWer ansWer);    /*添加ansWer*/

    int delet(std::string condition);   /*删除符合条件的数据*/

    int update(AnsWer ansWer);     /*根据主键修改整行数据*/

    std::list<AnsWer> inquire(std::string condition);   /*根据condition条件查询数据*/

private:
    AnsWerDAO  *ansWerDAO = new AnsWerDAO();
};


#endif //TSHH_ANSWER_H
