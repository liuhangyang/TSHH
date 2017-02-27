//
// Created by yang on 16-8-4.
//

#include "QuestionDAO.h"
#include "../model/Question.hpp"
#include <list>
#include "../Util/Common.h"
#include "../Util/DButil.h"

int QuestionDAO::insert(Question question) {
    common *comm;
    std::string question_id = comm->IntToString(question.get_question_id());
    std::string ts_id = comm->IntToString(question.get_ts_id());
    std::string question_answertimes = comm->IntToString(question.get_question_answertimes());
    std::string course_id = comm->IntToString(question.get_course_id());
    std::string big_class_id = comm->IntToString(question.get_big_class_id());

    std::string sql = "INSERT INTO question(question_id,ts_id,question_content,question_answertimes,course_id,big_class_id) VALUES('null','"
                      + ts_id + "','"
                      + question.get_question_content() + "','"
                      + question_answertimes + "','"
                      + course_id + "','"
                      + big_class_id + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int QuestionDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM question WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}
int QuestionDAO::updat(Question question)
{
    common *comm;
    std::string question_id = comm->IntToString(question.get_question_id());
    std::string ts_id = comm->IntToString(question.get_ts_id());
    std::string question_answertimes = comm->IntToString(question.get_question_answertimes());
    std::string course_id = comm->IntToString(question.get_course_id());
    std::string big_class_id = comm->IntToString(question.get_big_class_id());

    std::string sql = "UPDATE question SET ts_id = '" + ts_id
                      + "', question_content = '" + question.get_question_content()
                      + "', question_answertimes = '" + question_answertimes
                      + "', course_id = '" + course_id
                      + "', big_class_id = '" + big_class_id
                      + "' WHERE question_id = '" + question_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<Question> QuestionDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<Question> question_list;

    std::string sql = "SELECT * FROM question WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);

    while(res->next())
    {
        Question *question = new Question();
        question->set_question_id(res->getInt("question_id"));
        question->set_ts_id(res->getInt("ts_id"));
        question->set_question_content(res->getString("question_content"));
        question->set_question_answertimes(res->getInt("question_answertimes"));
        question->set_course_id(res->getInt("course_id"));
        question->set_big_class_id(res->getInt("big_class_id"));

        question_list.push_back(*question);
    }
    return question_list;
}