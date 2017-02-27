//
// Created by yang on 16-8-4.
//

#include "BigClassDAO.h"

#include "../model/BigClass.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"
#include <list>

int BigClassDAO::insert(BigClass bigClass) {
    common *comm;
    std::string big_class_id = comm->IntToString(bigClass.get_big_class_id());
    std::string big_class_people_num = comm->IntToString(bigClass.get_big_class_people_num());
    std::string ts_id = comm->IntToString(bigClass.get_ts_id());
    std::string course_id = comm->IntToString(bigClass.get_course_id());

    std::string sql = "insert into big_class(big_class_id,big_class_name,big_class_people_num,ts_id, course_id) values(null, '"
                      + big_class_id + "','"
                      + big_class_people_num+ "' , '"
                      + ts_id +"','"
                      + course_id + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int BigClassDAO::delet(std::string condition)
{
    std::string sql = "DELETE FROM big_class WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int BigClassDAO::update(BigClass bigClass)
{
    common *comm;
    std::string big_class_id = comm->IntToString(bigClass.get_big_class_id());
    std::string big_class_people_num = comm->IntToString(bigClass.get_big_class_people_num());
    std::string ts_id = comm->IntToString(bigClass.get_ts_id());
    std::string course_id = comm->IntToString(bigClass.get_course_id());

    std::string sql = "UPDATE big_class SET big_class_id = '" + big_class_id
                      + "',big_class_name = '" + bigClass.get_big_class_name()
                      + "',ts_id = '" + ts_id
                      + "',course_id = '" + course_id
                      + "' WHERE big_class_id = " + big_class_id;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<BigClass> BigClassDAO::find(std::string condition)
{
    std::list<BigClass> bigclass_list;
    ResultSet *res;
    std::string sql = "SELECT * FROM big_class WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    /*将结果集内容加入list*/
    while(res->next())
    {
        BigClass *bigClass = new BigClass();
        bigClass->set_big_class_id(res->getInt("big_class_id"));
        bigClass->set_big_class_name(res->getString("big_class_name"));
        bigClass->set_big_class_people_num(res->getInt("big_class_people_num"));
        bigClass->set_ts_id(res->getInt("ts_id"));
        bigClass->set_course_id(res->getInt("course_id"));

        bigclass_list.push_back(*bigClass);
    }
    return bigclass_list;
}