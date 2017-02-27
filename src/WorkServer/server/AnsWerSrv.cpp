//
// Created by yang on 16-8-5.
//

#include "AnsWerSrv.h"

#include "../model/AnsWer.hpp"


int AnsWerSrv::add(AnsWer ansWer) {
        return ansWerDAO->insert(ansWer);
}

int AnsWerSrv::delet(std::string condition)
{
    return ansWerDAO->dele(condition);
}

int AnsWerSrv::update(AnsWer ansWer)
{
    return ansWerDAO->updat(ansWer);
}

std::list<AnsWer> AnsWerSrv::inquire(std::string condition)
{
    return ansWerDAO->find(condition);
}