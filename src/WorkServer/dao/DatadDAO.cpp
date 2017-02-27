//
// Created by yang on 16-8-4.
//

#include "DatadDAO.h"
#include "../model/Datad.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"
#include <list>

int DatadDAO::insert(Datad datad)
{
    common *comm;
    std::string ts_id = comm->IntToString(datad.get_ts_id());
    std::string course_id = comm->IntToString(datad.get_course_id());
    std::string datad_size = comm->IntToString(datad.get_datad_size());
    std::string datad_downloadtimes = comm->IntToString(datad.get_datad_downloadtimes());
    std::string sql = "INSERT INTO datad(datad_id,ts_id,course_id,datad_size,datad_content,datad_downloadtimes ) VALUES ('null','"
                      + ts_id + "','"
                      + course_id + "','"
                      + datad_size + "','"
                      + datad.get_datad_content() + "','"
                      + datad_downloadtimes + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int DatadDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM datad WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int DatadDAO::updat(Datad datad)
{
    common *comm;
    std::string datad_id = comm->IntToString(datad.get_datad_id());
    std::string ts_id = comm->IntToString(datad.get_ts_id());
    std::string course_id = comm->IntToString(datad.get_course_id());
    std::string datad_size = comm->IntToString(datad.get_datad_size());
    std::string datad_downloadtimes = comm->IntToString(datad.get_datad_downloadtimes());

    std::string sql = "UPDATE datad SET ts_id = '" + ts_id
                      + "', course_id = '" + course_id
                      + "', datad_size = '" + datad_size
                      + "', datad_content = '" + datad.get_datad_content()
                      + "', datad_downloadtimes = '" + datad_downloadtimes
                      + "' WHERE datad_id = " + datad_id;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<Datad> DatadDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<Datad> datad_list;

    std::string sql = "SELECT * FROM datad WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        Datad *datad = new Datad();
        datad->set_datad_id(res->getInt("datad_id"));
        datad->set_ts_id(res->getInt("ts_id"));
        datad->set_course_id(res->getInt("course_id"));
        datad->set_datad_size(res->getInt("datad_size"));
        datad->set_datad_content(res->getString("datad_content"));
        datad->set_datad_downloadtimes(res->getInt("datad_downloadtimes"));

        datad_list.push_back(*datad);
    }
    return datad_list;
}