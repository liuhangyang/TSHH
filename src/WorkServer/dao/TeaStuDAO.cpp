//
// Created by yang on 16-8-4.
//

#include "TeaStuDAO.h"
#include "../model/TeaStu.hpp"
#include <list>
#include "../Util/DButil.h"
#include "../Util/Common.h"

int TeaStuDAO::insert(TeaStu teaStu)
{
    common *comm;
    std::string ts_id = comm->IntToString(teaStu.get_ts_id());
    std::string college_id = comm->IntToString(teaStu.get_college_id());
    std::string dept_id = comm->IntToString(teaStu.get_dept_id());
    std::string single_class_id = comm->IntToString(teaStu.get_single_class_id());

    std::string sql = "INSERT INTO ts(ts_id,ts_num,ts_name,college_id,dept_id,single_class_id,ts_introduction) VALUES('null','"
                      + teaStu.get_ts_num() + "','"
                      + teaStu.get_ts_name() + "','"
                      + college_id + "','"
                      + dept_id + "','"
                      + single_class_id + "','"
                      + teaStu.get_ts_introduction() + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
int dele(std::string condition)
{
    std::string sql = "DELETE FROM ts WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
int updat(TeaStu teaStu)
{
    common *comm;

    std::string ts_id = comm->IntToString(teaStu.get_ts_id());
    std::string college_id = comm->IntToString(teaStu.get_college_id());
    std::string dept_id = comm->IntToString(teaStu.get_dept_id());
    std::string single_class_id = comm->IntToString(teaStu.get_single_class_id());

    std::string sql = "UPDATE ts SET ts_num ='" + teaStu.get_ts_num()
                      +"',ts_name = '" + teaStu.get_ts_name()
                      + "', college_id = '" + college_id
                      + "', dept_id = '" + dept_id
                      + "', single_class_id = '" + single_class_id
                      + "', ts_introduction = '" + teaStu.get_ts_introduction()
                      + "' WHERE ts_id = '" + ts_id + "'";

    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
std::list<TeaStu> find(std::string condition)
{
    ResultSet *res;
    std::list<TeaStu> teastu_list;

    std::string sql = "SELECT * FROM ts WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        TeaStu *teaStu = new TeaStu();
        teaStu->set_ts_id(res->getInt("ts_id"));
        teaStu->set_ts_num(res->getString("ts_num"));
        teaStu->set_ts_name(res->getString("ts_name"));
        teaStu->set_college_id(res->getInt("college_id"));
        teaStu->set_dept_id(res->getInt("dept_id"));
        teaStu->set_single_class_id(res->getInt("single_class_id"));
        teaStu->set_ts_introduction(res->getString("ts_introduction"));

        teastu_list.push_back(*teaStu);
    }
    return teastu_list;
}
