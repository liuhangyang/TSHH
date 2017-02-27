//
// Created by yang on 16-8-5.
//

#ifndef TSHH_ROLLCALL_HPP
#define TSHH_ROLLCALL_HPP


class RollCall {
public:
    RollCall() = default;

    ~RollCall() = default;

    RollCall(int ro_id, int ro_we, int sc_co_id, int big_cl_id, int t_id, int ro_ye, int ro_no) {
        this->rollcall_id = ro_id;
        this->rollcall_week = ro_we;
        this->schedule_course_id = sc_co_id;
        this->big_class_id = big_cl_id;
        this->ts_id = t_id;
        this->rollcall_yes = ro_ye;
        this->rollcall_no = ro_no;
    }

    /*get方法*/
    int get_rollcall_id() {
        return this->rollcall_id;
    }
    int get_rollcall_week() {
        return this->rollcall_week;
    }
    int get_schedule_course_id() {
        return this->schedule_course_id;
    }
    int get_big_class_id() {
        return this->big_class_id;
    }
    int get_ts_id() {
        return this->ts_id;
    }
    int get_rollcall_yes() {
        return this->rollcall_yes;
    }
    int get_rollcall_no() {
        return this->rollcall_no;
    }

    /*set方法*/
    void set_rollcall_id(int ro_id) {
        this->rollcall_id = ro_id;
    }

    void set_rollcall_week(int ro_we) {
        this->rollcall_week = ro_we;
    }

    void set_schedule_course_id(int sc_co_id) {
        this->schedule_course_id = sc_co_id;
    }

    void set_big_class_id(int big_cl_id)
    {
        this->big_class_id = big_cl_id;
    }
    void set_ts_id(int t_id)
    {
        this->ts_id = t_id;
    }
    void set_rollcall_yes(int ro_ye)
    {
        this->rollcall_yes = ro_ye;
    }
    void set_rollcall_no(int ro_no)
    {
        this->rollcall_no = ro_no;
    }
private:
    int rollcall_id;        /*主键*/
    int rollcall_week;          /*周   外键*/
    int schedule_course_id;     /*确定哪一节课  外键*/
    int big_class_id;           /*大班的ID   外键*/
    int ts_id;                  /*老师的ID   外键*/
    int rollcall_yes;           /*到的人数 */
    int rollcall_no;            /*未到的人数 总人数-到了的人数*/

};


#endif //TSHH_ROLLCALL_HPP
