//
// Created by yang on 16-8-5.
//

#ifndef TSHH_QUESTION_HPP
#define TSHH_QUESTION_HPP

#include "../model/Question.hpp"
#include <list>
#include <string>
class Question {
public:
    Question() = default;
    ~Question() = default;
    Question(int qu_id,int t_id,std::string qu_co,int qu_an,int co_id,int big_cl_id)
    {
        this->question_id = qu_id;
        this->ts_id = t_id;
        this->question_content = qu_co;
        this->question_answertimes = qu_an;
        this->course_id = co_id;
        this->big_class_id = big_cl_id;
    }

    /*get方法*/
    int get_question_id()
    {
        return this->question_id;
    }
    int get_ts_id()
    {
        return this->ts_id;
    }
    std::string get_question_content()
    {
        return this->question_content;
    }
    int get_question_answertimes()
    {
        return this->question_answertimes;
    }
    int get_course_id()
    {
        return this->course_id;
    }
    int get_big_class_id()
    {
        return this->big_class_id;
    }

    /*set方法*/
    void set_question_id(int qu_id)
    {
        this->question_id = qu_id;
    }
    void set_ts_id(int t_id)
    {
        this->ts_id = t_id;
    }
    void set_question_content(std::string qu_co)
    {
        this->question_content = qu_co;
    }
    void set_question_answertimes(int qu_an)
    {
        this->question_answertimes = qu_an;
    }
    void set_course_id(int co_id)
    {
        this->course_id = co_id;
    }
    void set_big_class_id(int big_cl_id)
    {
        this->big_class_id = big_cl_id;
    }

private:
    int question_id;     /*主键*/
    int ts_id;           /*提问者*/
    std::string question_content;   /*问题*/
    int question_answertimes;   /*问题的回答个数*/
    int course_id;       /*课程ID:问题类型 外键*/
    int big_class_id;    /*问题提出的大班ID*/
};


#endif //TSHH_QUESTION_HPP
