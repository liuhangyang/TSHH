//
// Created by kiosk on 8/9/16.
//

#ifndef TSHH_CLASSROOMSRV_H
#define TSHH_CLASSROOMSRV_H

#include "../model/Classroom.hpp"
#include "../dao/ClassroomDAO.h"

class ClassroomSrv
{
public:
    ClassroomSrv() = default;
    ~ClassroomSrv() = default;

    int add(Classroom classroom);
    int delet(std::string condition);
    int update(Classroom classroom);
    std::list<Classroom> inquire(std::string condition);

private:
    ClassroomDAO *classroomDAO = new ClassroomDAO();
};

#endif //TSHH_CLASSROOMSRV_H
