//
// Created by yang on 16-8-5.
//

#ifndef TSHH_SINGLECLASS_HPP
#define TSHH_SINGLECLASS_HPP

#include <string>
class SingleClass {
public:
    SingleClass() = default;
    ~SingleClass() = default;
    SingleClass(int si_cl_id,std::string si_cl_na,int si_cl_nu,int de_id,int co_id)
    {
        this->single_class_id = si_cl_id;
        this->single_class_name = si_cl_na;
        this->single_class_num = si_cl_nu;
        this->dept_id = de_id;
        this->college_id = co_id;
    }
    /*get 方法*/
    int get_single_class_id()
    {
        return single_class_id;
    }
    std::string get_single_class_name()
    {
        return single_class_name;
    }
    int get_single_class_num()
    {
        return single_class_num;
    }
    int get_dept_id()
    {
        return dept_id;
    }
    int get_college_id()
    {
        return college_id;
    }

    /*set方法*/

    void set_single_class_id( int si_cl_id)
    {
        this->single_class_id = si_cl_id;
    }
    void set_single_class_name(std::string si_cl_na)
    {
        this->single_class_name = si_cl_na;
    }
    void set_single_class_num(int si_cl_nu)
    {
        this->single_class_num = si_cl_nu;
    }
    void set_dept_id(int de_id)
    {
        this->dept_id = de_id;
    }
    void set_college_id(int co_id)
    {
        this->college_id = co_id;
    }

private:
    int single_class_id;    /*主键*/
    std::string single_class_name;  /*班级名称*/
    int single_class_num;   /*班级人数*/
    int dept_id;   /*所在系  外键*/
    int college_id;   /*所在学院 外键*/
};


#endif //TSHH_SINGLECLASS_HPP
