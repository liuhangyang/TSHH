//
// Created by yang on 16-8-5.
//

#include "QuestionSrv.h"
#include "../model/Question.hpp"
#include "../dao/QuestionDAO.h"

int QuestionSrv::add(Question question)
{
    return questionDAO->insert(question);
}
int QuestionSrv::delet(std::string condition)
{
    return questionDAO->dele(condition);
}
int QuestionSrv::update(Question question)
{
    return questionDAO->updat(question);
}
std::list<Question> QuestionSrv::inquire(std::string condition)
{
    return questionDAO->find(condition);
}
