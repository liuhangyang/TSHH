//
// Created by yang on 16-8-4.
//

#include "SingleClassDAO.h"
#include "../model/SingleClass.hpp"
#include <list>
#include "../Util/DButil.h"
#include "../Util/Common.h"

int SingleClassDAO::insert(SingleClass singleClass)
{
    common *comm;
    std::string single_class_id = comm->IntToString(singleClass.get_single_class_id());
    std::string single_class_num = comm->IntToString(singleClass.get_single_class_num());
    std::string dept_id = comm->IntToString(singleClass.get_dept_id());
    std::string college_id = comm->IntToString(singleClass.get_college_id());

    std::string sql = "INSERT INTO single_class(single_class_id,single_class_name,single_class_num,dept_id,college_id)VALUES('null','"
                      + singleClass.get_single_class_name() + "','"
                      + single_class_num + "','"
                      + dept_id + "','"
                      + college_id + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int SingleClassDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM single_class WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int SingleClassDAO::updat(SingleClass singleClass)
{
    common *comm;
    std::string single_class_id = comm->IntToString(singleClass.get_single_class_id());
    std::string single_class_num = comm->IntToString(singleClass.get_single_class_num());
    std::string dept_id = comm->IntToString(singleClass.get_dept_id());
    std::string college_id = comm->IntToString(singleClass.get_college_id());

    std::string sql = "UPDATE single_class SET single_class_name = '" + singleClass.get_single_class_name()
                      + "',single_class_num = '" + single_class_num
                      + "',dept_id = '"+ dept_id
                      + "', college_id = '" + college_id
                      + "' WHERE single_class_id = '" + single_class_id + "'";

    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
std::list<SingleClass> SingleClassDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<SingleClass> singleclass_list;

    std::string sql = "SELECT * FROM single_class WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        SingleClass *singleClass = new SingleClass();
        singleClass->set_single_class_id(res->getInt("single_class_id"));
        singleClass->set_single_class_name(res->getString("single_class_name"));
        singleClass->set_single_class_num(res->getInt("single_num"));
        singleClass->set_dept_id(res->getInt("dept_id"));
        singleClass->set_college_id(res->getInt("college_id"));

        singleclass_list.push_back(*singleClass);
    }
    return singleclass_list;
}
