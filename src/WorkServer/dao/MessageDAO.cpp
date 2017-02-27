//
// Created by yang on 16-8-4.
//

#include "MessageDAO.h"
#include "../model/Message.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"
#include <list>

int MessageDAO::insert(Message message)
{
    common *comm;
    std::string message_id = comm->IntToString(message.get_message_id());
    std::string message_type = comm->IntToString(message.get_message_type());
    std::string ts_id_from = comm->IntToString(message.get_ts_id_from());
    std::string ts_id_to = comm->IntToString(message.get_ts_id_to());
    std::string message_status = comm->IntToString(message.get_message_status());
    std::string sql = "INSERT INTO message(message_id,message_type,ts_id_from,ts_id_to,message_content,message_time) VALUES('null','"
                      + message_type + "','"
                      + ts_id_from + "','"
                      + ts_id_to + "','"
                      + message.get_message_content() + "','"
                      + message_status + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int MessageDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM message WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int MessageDAO::updat(Message message)
{
    common *comm;
    std::string message_id = comm->IntToString(message.get_message_id());
    std::string message_type = comm->IntToString(message.get_message_type());
    std::string ts_id_from = comm->IntToString(message.get_ts_id_from());
    std::string ts_id_to = comm->IntToString(message.get_ts_id_to());
    std::string message_status = comm->IntToString(message.get_message_status());

    std::string sql = "UPDATE message SET message_type = '" + message_type
                      + "', ts_id_from = '" + ts_id_from
                      + "',ts_id_to = '" + ts_id_to
                      + "', message_content = '" + message.get_message_content()
                      + "', message_status = '" + message_status
                      + "' WHERE message_id = '" + message_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
std::list<Message> MessageDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<Message> message_list;

    std::string sql = "SELECT * FROM message WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        Message *message = new Message();
        message->set_message_id(res->getInt("message_id"));
        message->set_message_type(res->getInt("message_type"));
        message->set_ts_id_from(res->getInt("ts_id_from"));
        message->set_ts_id_to(res->getInt("ts_id_to"));
        message->set_message_content(res->getString("message_content"));
        message->set_message_status(res->getInt("message_status"));

        message_list.push_back(*message);
    }
    return message_list;
}
