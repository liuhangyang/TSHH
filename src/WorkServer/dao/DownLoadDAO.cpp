//
// Created by yang on 16-8-4.
//

#include "DownLoadDAO.h"
#include "../model/DownLoad.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"
#include <list>
int DownLoadDAO::insert(DownLoad downLoad)
{
    common *comm;
    std::string datad_id = comm->IntToString(downLoad.get_datad_id());
    std::string ts_id = comm->IntToString(downLoad.get_ts_id());

    std::string sql = "INSERT INTO download(download_id,datad_id,ts_id) VALUES ('null','"
                      + datad_id + "','"
                      + ts_id + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int DownLoadDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM download WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int DownLoadDAO::updat(DownLoad downLoad)
{
    common *comm;
    std::string download_id = comm->IntToString(downLoad.get_download_id());
    std::string datad_id = comm->IntToString(downLoad.get_datad_id());
    std::string ts_id = comm->IntToString(downLoad.get_ts_id());

    std::string sql = "UPDATE download SET datad_id = '" + datad_id
                      + "', ts_id = '" + ts_id
                      + "' WHERE download_id = '" + download_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
std::list<DownLoad> DownLoadDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<DownLoad> download_list;

    std::string sql = "SELECT * FROM download WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        DownLoad *downLoad = new DownLoad();
        downLoad->set_download_id(res->getInt("download_id"));
        downLoad->set_datad_id(res->getInt("datad_id"));
        downLoad->set_ts_id(res->getInt("ts_id"));

        download_list.push_back(* downLoad);
    }
    return download_list;
}