//
// Created by yang on 16-8-5.
//

#ifndef TSHH_TEACHERPLAN_HPP
#define TSHH_TEACHERPLAN_HPP

#include <string>
class TeacherPlan {
public:
    TeacherPlan() = default;
    ~TeacherPlan() = default;
    TeacherPlan(int te_pl_id, int t_id, int te_pl_we, int cl_id, int sc_co_id, std::string te_pl_co, int te_pl_ty)
    {
        this->teacher_plan_id = te_pl_id;
        this->ts_id = t_id;
        this->teacher_plan_week = te_pl_we;
        this->classroom_id = cl_id;
        this->schedule_course_id = sc_co_id;
        this->teacher_plan_content = te_pl_co;
        this->teacher_plan_type = te_pl_ty;
    }
    /*get方法*/
    int get_teacher_plan_id()
    {
        return this->teacher_plan_id;
    }
    int get_ts_id()
    {
        return this->ts_id;
    }
    int get_teacher_plan_week()
    {
        return this->teacher_plan_week;
    }
    int get_classroom_id()
    {
        return this->classroom_id;
    }
    int get_schedule_course_id()
    {
        return this->schedule_course_id;
    }
    std::string get_teacher_plan_content()
    {
        return this->teacher_plan_content;
    }
    int get_teacher_plan_type()
    {
        return this->teacher_plan_type;
    }

    /*set方法*/
    void set_teacher_plan_id(int te_pl_id)
    {
        this->teacher_plan_id = te_pl_id;
    }
    void set_ts_id(int t_id)
    {
        this->ts_id = t_id;
    }
    void set_teacher_plan_week(int te_pl_we)
    {
        this->teacher_plan_week = te_pl_we;
    }
    void set_classroom_id(int cl_id)
    {
        this->classroom_id = cl_id;
    }
    void set_schedule_course_id(int sc_co_id)
    {
        this->schedule_course_id = sc_co_id;
    }
    void set_teacher_plan_content(std::string te_pl_co)
    {
        this->teacher_plan_content = te_pl_co;
    }
    void set_teacher_plan_type(int te_pl_ty)
    {
        this->teacher_plan_type = te_pl_ty;
    }

private:
    int teacher_plan_id;  /*主键*/
    int ts_id;            /*老师ID  外键*/
    int teacher_plan_week;   /*周 外键*/
    int classroom_id;     /*确定教室  外键*/
    int schedule_course_id;   /*确定哪一节课 外键*/
    std::string teacher_plan_content;   /*安排的上课内容 预习内容*/
    int teacher_plan_type;    /*0:上课1:实验2:上机 外键*/
};


#endif //TSHH_TEACHERPLAN_HPP
