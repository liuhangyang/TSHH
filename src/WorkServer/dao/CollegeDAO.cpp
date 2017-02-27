//
// Created by yang on 16-8-4.
//

#include "CollegeDAO.h"
#include "../model/College.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"
#include <list>

int CollegeDAO::insert(College college)
{
    std::string sql = "INSERT INTO college(college_id, college_name, college_introduction) VALUE ('null','"
                      + college.get_college_name() + "','"
                      + college.get_college_introduction() + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int CollegeDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM college WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int CollegeDAO::updat(College college)
{
    common *comm;
    std::string college_id = comm->IntToString(college.get_college_id());
    std::string sql = "UPDATE college SET college_name = '"
                      + college.get_college_name()
                      + "',college_introduction = '"
                      + college.get_college_introduction()
                      + "' WHERE college_id = '"+ college_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}




std::list<College> CollegeDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<College> college_list;
    std::string sql = "SELECT * FROM college WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        College *college = new College();
        college->set_college_id(res->getInt("college_id"));
        college->set_college_name(res->getString("college_name"));
        college->set_college_introduction(res->getString("college_introduction"));

        college_list.push_back(*college);
    }
    return college_list;

}