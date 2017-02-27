//
// Created by yang on 16-8-5.
//

#ifndef TSHH_CLASSROOM_HPP
#define TSHH_CLASSROOM_HPP

#include <string>
class Classroom {
public:
    Classroom() = default;
    ~Classroom() = default;
    Classroom( int cl_id, std::string cl_na, std::string cl_wa )
    {
        this->classroom_id = cl_id;
        this->classroom_name = cl_na;
        this->classroom_way = cl_wa;
    }

    /*get 方法*/
    int get_classroom_id()
    {
        return this->classroom_id;
    }
    std::string get_classroom_name()
    {
        return this->classroom_name;
    }
    std::string get_classroom_way()
    {
        return this->classroom_way;
    }

    /*set方法*/
    void set_classroom_id( int cl_id )
    {
        this->classroom_id = cl_id;
    }

    void set_classroom_name( std::string cl_na)
    {
        this->classroom_name = cl_na;
    }

    void set_classroom_way( std::string cl_wa)
    {
        this->classroom_way = cl_wa;
    }

private:
    int classroom_id;        /*主键*/
    std::string classroom_name;  /*教室名称*/
    std::string classroom_way;   /*教室路径*/
};


#endif //TSHH_CLASSROOM_HPP
