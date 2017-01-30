//
// Created by yang on 16-8-4.
//

#include "TeaStuPasswdDAO.h"
#include "../model/TeaStuPasswd.hpp"
#include "../Util/DButil.h"
#include "../Util/Common.h"
#include <list>

int insert(TeaStuPasswd teaStuPasswd)
{
    common *comm;

    std::string ts_passwd_id = comm->IntToString(teaStuPasswd.get_ts_passwd_id());
    std::string ts_id = comm->IntToString(teaStuPasswd.get_ts_id());

    std::string sql = "INSERT INTO ts_passwd(ts_passwd_id,ts_id,ts_passwd_content) VALUES('null','"
                      + ts_id + "','"
                      + teaStuPasswd.get_ts_passwd_content() + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int dele(std::string condition)
{
    std::string sql = "DELETE FROM ts_passwd WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;

}
int updat(TeaStuPasswd teaStuPasswd)
{
    common *comm;

    std::string ts_passwd_id = comm->IntToString(teaStuPasswd.get_ts_passwd_id());
    std::string ts_id = comm->IntToString(teaStuPasswd.get_ts_id());

    std::string sql = "UPDATE ts_passwd SET ts_id = '" + ts_id
                      + "', ts_passwd_content = '" + teaStuPasswd.get_ts_passwd_content()
                      + "' WHERE ts_passwd_id = '" + ts_passwd_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;

}
std::list<TeaStuPasswd> find(std::string condition)
{
    ResultSet *res;
    std::list<TeaStuPasswd> teastupasswd_list;

    std::string sql = "SELECT * FROM ts_passwd WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        TeaStuPasswd *teaStuPasswd = new TeaStuPasswd();
        teaStuPasswd->set_ts_passwd_id(res->getInt("ts_passwd_id"));
        teaStuPasswd->set_ts_id(res->getInt("ts_id"));
        teaStuPasswd->set_ts_passwd_content(res->getString("ts_passwd_content"));

        teastupasswd_list.push_back(*teaStuPasswd);
    }
    return teastupasswd_list;
}