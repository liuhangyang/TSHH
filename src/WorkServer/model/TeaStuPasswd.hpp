//
// Created by yang on 16-8-5.
//

#ifndef TSHH_TEASTUPASSWD_HPP
#define TSHH_TEASTUPASSWD_HPP

#include <string>
class TeaStuPasswd {
public:
    TeaStuPasswd() = default;

    ~TeaStuPasswd() = default;

    TeaStuPasswd(int ts_pa_id, int t_id, std::string ts_pa_co) {
        this->ts_passwd_id = ts_pa_id;
        this->ts_id = t_id;
        this->ts_passwd_content = ts_pa_co;
    }

    /*get方法*/
    int get_ts_passwd_id() {
        return this->ts_passwd_id;
    }

    int get_ts_id() {
        return this->ts_id;
    }

    std::string get_ts_passwd_content() {
        return this->ts_passwd_content;
    }

    /*set方法*/
    void set_ts_passwd_id(int ts_pa_id) {
        this->ts_passwd_id = ts_pa_id;
    }

    void set_ts_id(int t_id) {
        this->ts_id = t_id;
    }

    void set_ts_passwd_content(std::string ts_pa_co)
    {
        this->ts_passwd_content = ts_pa_co;
    }

private:
    int ts_passwd_id;   /*主键*/
    int ts_id;          /*老师学生ID*/
    std::string ts_passwd_content;  /*密码*/
};


#endif //TSHH_TEASTUPASSWD_HPP
