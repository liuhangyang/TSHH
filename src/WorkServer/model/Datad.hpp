//
// Created by two eggs on 16-8-5.
//

#ifndef TSHH_DATAD_HPP
#define TSHH_DATAD_HPP

#include <string>
class Datad {
public:
    Datad() = default;
    ~Datad() = default;
    Datad(int da_id, int t_id, int co_id, int da_si,std::string da_co, int da_do)
    {
        this->datad_id = da_id;
        this->ts_id = t_id;
        this->course_id = co_id;
        this->datad_size = da_si;
        this->datad_content = da_co;
        this->datad_downloadtimes = da_do;
    }

    /*get方法*/
    int get_datad_id()
    {
        return this->datad_id;
    }
    int get_ts_id()
    {
        return this->ts_id;
    }
    int get_course_id()
    {
        return this->course_id;
    }
    int get_datad_size()
    {
        return this->datad_size;
    }
    std::string get_datad_content()
    {
        return this->datad_content;
    }
    int get_datad_downloadtimes()
    {
        return this->datad_downloadtimes;
    }

    /*set方法*/
    void set_datad_id( int da_id)
    {
        this->datad_id = da_id;
    }
    void set_ts_id(int t_id)
    {
        this->ts_id = t_id;
    }
    void set_course_id(int co_id)
    {
        this->course_id = co_id;
    }
    void set_datad_size(int da_si)
    {
        this->datad_size = da_si;
    }
    void set_datad_content(std::string da_co)
    {
        this->datad_content = da_co;
    }
    void set_datad_downloadtimes(int da_do)
    {
        this->datad_downloadtimes = da_do;
    }

private:
    int datad_id;       /*主键*/
    int ts_id;          /*老师/学生ID*/
    int course_id;      /*资料分类*/
    int datad_size;     /*资料大小*/
    std::string datad_content;  /*资料的路径*/
    int datad_downloadtimes;    /*下载次数*/
};


#endif //TSHH_DATAD_HPP
