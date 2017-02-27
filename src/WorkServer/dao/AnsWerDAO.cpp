//
// Created by yang on 16-8-4.
//

#include "AnsWerDAO.h"

#include "../model/AnsWer.hpp"
#include "../Util/Common.h"
#include "../Util/DButil.h"
#include <list>

int AnsWerDAO::insert(AnsWer ansWer) {
    common *comm;
    std::string answer_id = comm->IntToString(ansWer.get_answer_id());
    std::string ts_id = comm->IntToString(ansWer.get_ts_id());
    std::string question_id = comm->IntToString(ansWer.get_question_id());

    std::string sql = "insert into answer(answer_id,ts_id,question_id,answer_content) values(null, '"
                      +ts_id + "','"
                      +question_id+ "' , '"
                      +ansWer.get_answer_content() +"')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int AnsWerDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM answer WHERE"
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int AnsWerDAO::updat(AnsWer ansWer)
{
    common *comm;
    std::string answer_id = comm->IntToString(ansWer.get_answer_id());
    std::string ts_id = comm->IntToString(ansWer.get_ts_id());
    std::string question_id = comm->IntToString(ansWer.get_question_id());

    std::string sql = "UPDATE answer SET ts_id = '" + ts_id
                      + "',question_id = '" + question_id
                      + "',answer_content = '" + ansWer.get_answer_content()
                      + "' WHERE answer_id = " + answer_id;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<AnsWer> AnsWerDAO::find(std::string condition)
{
    std::list<AnsWer> answer_list;
    ResultSet *res;
    std::string sql = "SELECT * FROM answer WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    /*将结果集内容加入list*/
    while(res->next())
    {
        AnsWer *ansWer = new AnsWer();
        ansWer->set_answer_id(res->getInt("answer_id"));
        ansWer->set_ts_id(res->getInt("ts_id"));
        ansWer->set_question_id(res->getInt("question_id"));
        ansWer->set_answer_content(res->getString("answer_content"));

        answer_list.push_back(*ansWer);
    }
    return answer_list;
}