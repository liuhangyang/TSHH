//
// Created by yang on 16-8-5.
//

#ifndef TSHH_COURSE_HPP
#define TSHH_COURSE_HPP

#include <string>
class Course {
public:
    Course() = default;
    ~Course() = default;
    Course( int co_id, int de_id, std::string co_na, std::string co_in)
    {
        this->course_id = co_id;
        this->dept_id = de_id;
        this->course_name = co_na;
        this->course_introduction = co_in;
    }
    /*get方法*/
    int get_course_id()
    {
        return this->course_id;
    }
    int get_dept_id()
    {
        return this->dept_id;
    }
    std::string get_course_name()
    {
        return this->course_name;
    }
    std::string get_course_introduction()
    {
        return this->course_introduction;
    }

    /*set方法*/
    void set_course_id( int co_id)
    {
        this->course_id = co_id;
    }
    void set_dept_id( int de_id )
    {
        this->dept_id = de_id;
    }
    void set_course_name( std::string co_na)
    {
        this->course_name = co_na;
    }
    void set_course_introduction(std::string co_in)
    {
        this->course_introduction = co_in;
    }

private:
    int course_id;    /*主键*/
    int dept_id;      /*属于的系  外键*/
    std::string course_name;    /*课程名*/
    std::string course_introduction;   /*课程介绍*/
};


#endif //TSHH_COURSE_HPP
