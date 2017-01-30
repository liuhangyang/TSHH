//
// Created by yang on 16-8-5.
//

#ifndef TSHH_TEASTU_HPP
#define TSHH_TEASTU_HPP

#include <list>
#include <string>
class TeaStu {
public:
    TeaStu() = default;
    ~TeaStu() = default;
    TeaStu(int t_id,std::string ts_nu,std::string ts_na,int co_id,int de_id,int si_cl_id,std::string ts_in)
    {
        this->ts_id = t_id;
        this->ts_num = ts_nu;
        this->ts_name = ts_na;
        this->college_id = co_id;
        this->dept_id = de_id;
        this->single_class_id = si_cl_id;
        this->ts_introduction = ts_in;
    }
    /*get方法*/
    int get_ts_id()
    {
        return  this->ts_id;
    }
    std::string get_ts_num()
    {
        return this->ts_num;
    }
    std::string get_ts_name()
    {
        return this->ts_name;
    }
    int get_college_id()
    {
        return this->college_id;
    }
    int get_dept_id()
    {
        return this->dept_id;
    }
    int get_single_class_id()
    {
        return this->single_class_id;
    }
    std::string get_ts_introduction()
    {
        return this->ts_introduction;
    }

    /*set方法*/
    void set_ts_id(int t_id)
    {
        this->ts_id = t_id;
    }
    void set_ts_num(std::string ts_nu)
    {
        this->ts_num = ts_nu;
    }
    void set_ts_name(std::string ts_na)
    {
        this->ts_name = ts_na;
    }
    void set_college_id(int co_id)
    {
        this->college_id = co_id;
    }
    void set_dept_id(int de_id)
    {
        this->dept_id = de_id;
    }
    void set_single_class_id(int si_cl_id)
    {
        this->single_class_id = si_cl_id;
    }
    void set_ts_introduction(std::string ts_in)
    {
        this->ts_introduction = ts_in;
    }

private:
    int ts_id;   /*主键*/
    std::string ts_num;  /*老师学生学号*/
    std::string ts_name;   /*姓名*/
    int college_id;         /*所在学院  外键*/
    int dept_id;            /*所在系 外键*/
    int single_class_id;    /*所在班级 外键*/
    std::string ts_introduction;  /*自我介绍*/
};


#endif //TSHH_TEASTU_HPP
