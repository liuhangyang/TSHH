//
// Created by yang on 16-8-5.
//

#ifndef TSHH_COLLEGE_HPP
#define TSHH_COLLEGE_HPP

#include <string>
class College {
public:
    College() = default;
    ~College() = default;
    College( int co_id, std::string co_na, std::string co_in)
    {
        this->college_id = co_id;
        this->college_name = co_na;
        this->college_introduction = co_in;
    }

    /*get 方法*/
    int get_college_id()
    {
        return this->college_id;
    }

    std::string get_college_name()
    {
        return this->college_name;
    }

    std::string get_college_introduction()
    {
        return this->college_introduction;
    }

    /*set 方法*/
    void set_college_id( int co_id )
    {
        this->college_id = co_id;
    }

    void set_college_name( std::string co_na)
    {
        this->college_name = co_na;
    }

    void set_college_introduction( std::string co_in)
    {
        this->college_introduction = co_in;
    }

private:
    int college_id;     /*主键*/
    std::string college_name;      /*学院名称*/
    std::string college_introduction;       /*学院介绍*/
};


#endif //TSHH_COLLEGE_HPP
