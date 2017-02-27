//
// Created by yang on 16-8-4.
//

#include "BigClassListDAO.h"
#include <list>
#include "../model/BigClassList.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"

int insert(BigClassList bigClassList)
{
    common *comm;
    std::string big_class_id = comm->IntToString(bigClassList.get_big_class_id());
    std::string single_class_id = comm->IntToString(bigClassList.get_single_class_id());

    std::string sql = "INSERT INTO big_class_list(big_class_id, single_class_id) VALUE ( '"
                      + big_class_id + "','"
                      + single_class_id + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int delet(std::string condition)
{
    std::string sql = "DELETE FROM big_class_list WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int updat(BigClassList bigClassList)
{
    common *comm;
    std::string big_class_id = comm->IntToString(bigClassList.get_big_class_id());
    std::string single_class_id = comm->IntToString(bigClassList.get_single_class_id());

    std::string sql = "UPDATE big_class_list SET big_class_id = '"
                      +  big_class_id + "', single_class_id = '"
                      + single_class_id + "' WHERE single_class_id = '"
                      + single_class_id +"'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<BigClassList> find(std::string condition)
{
    std::list<BigClassList> bigclasslist_list;
    ResultSet *res;

    std::string sql = "SELECT * FROM big_class_list WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        BigClassList *bigClassList = new BigClassList();
        bigClassList->set_big_class_id(res->getInt("big_class_id"));
        bigClassList->set_single_class_id(res->getInt("single_class_id"));

        bigclasslist_list.push_back(*bigClassList);
    }
    return bigclasslist_list;
}