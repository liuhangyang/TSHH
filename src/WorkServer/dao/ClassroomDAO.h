//
// Created by yang on 16-8-4.
//

#ifndef TSHH_CLASSROOMDAO_H
#define TSHH_CLASSROOMDAO_H

#include "../model/Classroom.hpp"
#include <list>

class ClassroomDAO {
public:
    int insert(Classroom classroom);

    int dele(std::string condition);

    int updat(Classroom classroom);

    std::list<Classroom> find(std::string condition);
};


#endif //TSHH_CLASSROOMDAO_H
