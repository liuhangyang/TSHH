//
// Created by yang on 16-8-4.
//

#include "RollCallDAO.h"
#include "../model/RollCall.hpp"
#include <list>
#include "../Util/Common.h"
#include "../Util/DButil.h"

int RollCallDAO::insert(RollCall rollCall)
{
    common *comm;
    std::string rollcall_id = comm->IntToString(rollCall.get_rollcall_id());
    std::string rollcall_week = comm->IntToString(rollCall.get_rollcall_week());
    std::string schedule_course_id = comm->IntToString(rollCall.get_schedule_course_id());
    std::string big_class_id = comm->IntToString(rollCall.get_big_class_id());
    std::string ts_id = comm->IntToString(rollCall.get_ts_id());
    std::string rollcall_yes = comm->IntToString(rollCall.get_rollcall_yes());
    std::string rollcall_no = comm->IntToString(rollCall.get_rollcall_no());

    std::string sql = "INSERT INTO rollcall(rollcall_id,rollcall_week,schedule_course_id,big_class_id,ts_id, rollcall_yes,rollcall_no) VALUE('null','"
                      + rollcall_week + "','"
                      + schedule_course_id + "','"
                      + big_class_id + "','"
                      + ts_id + "','"
                      + rollcall_yes + "','"
                      + rollcall_no + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int RollCallDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM rollcall WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int RollCallDAO::updat(RollCall rollCall)
{
    common *comm;
    std::string rollcall_id = comm->IntToString(rollCall.get_rollcall_id());
    std::string rollcall_week = comm->IntToString(rollCall.get_rollcall_week());
    std::string schedule_course_id = comm->IntToString(rollCall.get_schedule_course_id());
    std::string big_class_id = comm->IntToString(rollCall.get_big_class_id());
    std::string ts_id = comm->IntToString(rollCall.get_ts_id());
    std::string rollcall_yes = comm->IntToString(rollCall.get_rollcall_yes());
    std::string rollcall_no = comm->IntToString(rollCall.get_rollcall_no());

    std::string sql = "UPDATE rollcall SET rollcall_week = '" + rollcall_week
                      + "',schedule_course_id = '" + schedule_course_id
                      + "',big_class_id = '" + big_class_id
                      + "',ts_id = '" + ts_id
                      + "',rollcall_yes = '" + rollcall_yes
                      + "',rollcall_no = '" + rollcall_no
                      + "' WHERE rollcall_id = '" + rollcall_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<RollCall> RollCallDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<RollCall> rollcall_list;

    std::string sql = "SELECT * FROM rollcall WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        RollCall *rollCall = new RollCall();
        rollCall->set_rollcall_id(res->getInt("rollcall_id"));
        rollCall->set_rollcall_week(res->getInt("rollcall_week"));
        rollCall->set_schedule_course_id(res->getInt("schedule_course_id");
        rollCall->set_big_class_id(res->getInt("big_class_id"));
        rollCall->get_ts_id(res->getInt("ts_id"));
        rollCall->get_rollcall_yes(res->getInt("rollcall_yes"));
        rollCall->get_rollcall_no(res->getInt("rollcall_no"));

        rollcall_list.push_back(rollCall);
    }
    return rollcall_list;
}
