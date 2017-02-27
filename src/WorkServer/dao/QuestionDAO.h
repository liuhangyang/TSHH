//
// Created by yang on 16-8-4.
//

#ifndef TSHH_QUESTIONDAO_H
#define TSHH_QUESTIONDAO_H
#include "../model/Question.hpp"
#include <list>
class QuestionDAO {

    int insert(Question question);

    int dele(std::string condition);

    int updat(Question question);

    std::list<Question> find(std::string condition);
};


#endif //TSHH_QUESTIONDAO_H
