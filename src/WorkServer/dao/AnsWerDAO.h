//
// Created by yang on 16-8-4.
//

#ifndef TSHH_ANSWERDAO_H
#define TSHH_ANSWERDAO_H


#include "../model/AnsWer.hpp"
#include <list>

class AnsWerDAO {
public:
    int insert( AnsWer ansWer );
    int dele( std::string condition );
    int updat( AnsWer ansWer );
    std::list<AnsWer> find( std::string condition );
};


#endif //TSHH_ANSWERDAO_H
