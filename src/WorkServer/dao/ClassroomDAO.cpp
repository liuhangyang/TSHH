//
// Created by yang on 16-8-4.
//

#include "ClassroomDAO.h"
#include "../model/Classroom.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"
#include <list>

int insert(Classroom classroom)
{
    std::string sql = "INSERT INTO classroom(classroom_id,classroom_name,classroom_way) VALUE ('null','"
                      + classroom.get_classroom_name()
                      + "','" + classroom.get_classroom_way()
                      + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int dele(std::string condition)
{
    std::string sql = "DELETE FROM classroom WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int updat(Classroom classroom)
{
    common *comm;
    std::string classroom_id = comm->IntToString(classroom.get_classroom_id());
    std::string sql = "UPDATE classroom SET classroom_name = ' "
                      + classroom.get_classroom_name()
                      + "',classroom_way = '"
                      + classroom.get_classroom_way()
                      + "' WHERE classroom_id = '"
                      + classroom_id + "' ";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<Classroom> find(std::string condition)
{
    ResultSet *res;
    std::list<Classroom> classroom_list;

    std::string sql = "SELECT * FROM classroom WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        Classroom *classroom = new Classroom();
        classroom->set_classroom_id(res->getInt("classroom_id"));
        classroom->set_classroom_name(res->getString("classroom_name"));
        classroom->set_classroom_way(res->getString("classroom_way"));

        classroom_list.push_back(*classroom);
    }
    return classroom_list;
}


