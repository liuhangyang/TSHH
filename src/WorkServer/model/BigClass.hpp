//
// Created by yang on 16-8-5.
//

#ifndef TSHH_BIGCLASS_HPP
#define TSHH_BIGCLASS_HPP

#include <string>
class BigClass {

public:
    BigClass() = default;
    ~BigClass() = default;
    BigClass( int big_cl_id, std::string big_cl_na, int big_cl_pe_nu, int t_id, int co_id)
    {
        this->big_class_id = big_cl_id;
        this->big_class_name = big_cl_na;
        this->big_class_people_num = big_cl_pe_nu;
        this->ts_id = t_id;
        this->course_id = co_id;
    }
    /*get 方法*/
    int get_big_class_id()
    {
        return this->big_class_id;
    }

    std::string get_big_class_name()
    {
        return this->big_class_name;
    }

    int get_big_class_people_num()
    {
        return this->big_class_people_num;
    }

    int get_ts_id()
    {
        return this->ts_id;
    }

    int get_course_id()
    {
        return this->course_id;
    }

    /*set 方法*/
    void set_big_class_id( int big_cl_id )
    {
        this->big_class_id = big_cl_id;
    }

    void set_big_class_name( std::string big_cl_na)
    {
        this->big_class_name = big_cl_na;
    }

    void set_big_class_people_num( int big_cl_pe_nu )
    {
        this->big_class_people_num = big_cl_pe_nu;
    }

    void set_ts_id( int t_id)
    {
        this->ts_id = t_id;
    }

    void set_course_id( int co_id)
    {
        this->course_id = co_id;
    }

private:
    int big_class_id;       /*主键*/
    std::string big_class_name;     /*大班名称*/
    int big_class_people_num;       /*总人数*/
    int ts_id;            /*老师ID*/
    int course_id;        /*课程ID*/


};


#endif //TSHH_BIGCLASS_HPP
