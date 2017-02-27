//
// Created by yang on 16-8-5.
//

#ifndef TSHH_QUESTION_H
#define TSHH_QUESTION_H
#include "../model/Question.hpp"
#include "../dao/QuestionDAO.h"
#include <list>

class QuestionSrv {
public:
    QuestionSrv() = default;
    ~QuestionSrv() = default;

    int add(Question question);

    int delet(std::string condition);

    int update(Question question);

    std::list<Question> inquire(std::string condition);

private:
    QuestionDAO *questionDAO = new QuestionDAO();
};


#endif //TSHH_QUESTION_H
