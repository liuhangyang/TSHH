//
// Created by yang on 16-8-5.
//

#ifndef TSHH_DEPT_HPP
#define TSHH_DEPT_HPP

class Dept {
public:
    Dept() = default;
    ~Dept() = default;
    Dept(int de_id, int co_id, std::string de_na, std::string de_in)
    {
        this->dept_id = de_id;
        this->college_id = co_id;
        this->dept_name = de_na;
        this->dept_introduction = de_in;
    }

    /*get方法*/
    int get_dept_id()
    {
        return this->dept_id;
    }
    int get_college_id()
    {
        return this->college_id;
    }
    std::string get_dept_name()
    {
        return this->dept_name;
    }
    std::string get_dept_introduction()
    {
        return this->dept_introduction;
    }

    /*set方法*/
    void set_dept_id(int de_id)
    {
        this->dept_id = de_id;
    }
    void set_college_id(int co_id)
    {
        this->college_id = co_id;
    }
    void set_dept_name(std::string de_na)
    {
        this->dept_name = de_na;
    }
    void set_dept_introduction(std::string de_in)
    {
        this->dept_introduction = de_in;
    }
private:
    int dept_id;   /*主键*/
    int college_id;    /*所属学院*/
    std::string dept_name;   /*专业名称*/
    std::string dept_introduction;   /*专业介绍*/

};


#endif //TSHH_DEPT_HPP
