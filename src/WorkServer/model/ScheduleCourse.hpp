//
// Created by yang on 16-8-5.
//

#ifndef TSHH_SCHEDULECOURSE_HPP
#define TSHH_SCHEDULECOURSE_HPP


class ScheduleCourse {
public:
    ScheduleCourse() = default;
    ~ScheduleCourse() = default;
    ScheduleCourse(int sc_co_id,int de_id,int si_cl_id,int sc_co_da,int sc_co_co,int cl_id,int co_id)
    {
        this->schedule_course_id = sc_co_id;
        this->dept_id = de_id;
        this->single_class_id = si_cl_id;
        this->schedule_course_day = sc_co_da;
        this->schedule_course_course = sc_co_co;
        this->classroom_id = cl_id;
        this->course_id = co_id;
    }

    /*get方法*/
    int get_schedule_course_id()
    {
        return this->schedule_course_id;
    }
    int get_dept_id()
    {
        return this->dept_id;
    }
    int get_single_class_id()
    {
        return this->single_class_id;
    }
    int get_schedule_course_day()
    {
        return this->schedule_course_day;
    }
    int get_schedule_course_course()
    {
        return this->schedule_course_course;
    }
    int get_classroom_id()
    {
        return this->classroom_id;
    }
    int get_course_id()
    {
        return this->course_id;
    }

    /*set方法*/
    void set_schedule_course_id(int sc_co_id)
    {
        this->schedule_course_id = sc_co_id;
    }
    void set_dept_id(int de_id)
    {
        this->dept_id = de_id;
    }
    void set_single_class_id(int si_cl_id)
    {
        this->single_class_id = si_cl_id;
    }
    void set_schedule_course_day(int sc_co_da)
    {
        this->schedule_course_day = sc_co_da;
    }
    void set_schedule_course_course(int sc_co_co)
    {
        this->schedule_course_course = sc_co_co;
    }
    void set_classroom_id(int cl_id)
    {
        this->classroom_id = cl_id;
    }
    void set_course_id(int co_id)
    {
        this->course_id = co_id;
    }
private:
    int schedule_course_id;     /*主键*/
    int dept_id;                /*属于的系  外键*/
    int single_class_id;        /*属于的班级  外键*/
    int schedule_course_day;    /*1-7 表示周一到周天*/
    int schedule_course_course; /*1-4 标示每天4节课*/
    int classroom_id;           /*确定每一个教室*/
    int course_id;              /*课程名*/
};


#endif //TSHH_SCHEDULECOURSE_HPP
