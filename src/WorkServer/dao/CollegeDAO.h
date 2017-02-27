//
// Created by yang on 16-8-4.
//

#ifndef TSHH_COLLEGEDAO_H
#define TSHH_COLLEGEDAO_H

#include <list>
#include "../model/College.hpp"

class CollegeDAO {
public:
    int insert(College college);
    int dele(std::string condition);
    int updat(College college);
    std::list<College> find(std::string condition);
};


#endif //TSHH_COLLEGEDAO_H
