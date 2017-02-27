//
// Created by yang on 16-8-4.
//

#include "DeptDAO.h"
#include "../model/Dept.hpp"
#include <list>
#include "../Util/Common.h"
#include "../Util/DButil.h"

int DeptDAO::insert(Dept dept)
{
    common *comm;
    std::string college_id = comm->IntToString(dept.get_college_id());

    std::string sql = "INSERT INTO dept(dept_id,college_id,dept_name,dept_introduction) VALUES ('null','"
                      + college_id + "','"
                      + dept.get_dept_name() + "','"
                      + dept.get_dept_introduction() + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int DeptDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM dept WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int DeptDAO::updat(Dept dept)
{
    common *comm;
    std::string dept_id = comm->IntToString(dept.get_dept_id());
    std::string college_id = comm->IntToString(dept.get_college_id());

    std::string sql = "UPDATE dept SET college_id = '" + college_id
                      + "', dept_name = '" + dept.get_dept_name()
                      + "', dept_introduction = '" + dept.get_dept_introduction()
                      + "' WHERE dept_id = '" + dept_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
std::list<Dept> DeptDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<Dept> dept_list;

    std::string sql = "SELECT * FROM dept WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        Dept *dept = Dept();
        dept->set_dept_id(res->getInt("dept_id"));
        dept->set_college_id(res->getInt("college_id"));
        dept->set_dept_name(res->getString("dept_name"));
        dept->set_dept_introduction(res->getString("dept_introduction"));

        dept_list.push_back(dept);
    }
    return dept_list;
}