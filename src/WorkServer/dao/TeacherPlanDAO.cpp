//
// Created by yang on 16-8-4.
//

#include "TeacherPlanDAO.h"
#include "../model/TeacherPlan.hpp"
#include <list>
#include "../Util/Common.h"
#include "../Util/DButil.h"

int TeacherPlanDAO::insert(TeacherPlan teacherPlan)
{
    common *comm;
    std::string teacher_plan_id = comm->IntToString(teacherPlan.get_teacher_plan_id());
    std::string ts_id = comm->IntToString(teacherPlan.get_ts_id());
    std::string teacher_plan_week = comm->IntToString(teacherPlan.get_teacher_plan_week());
    std::string classroom_id = comm->IntToString(teacherPlan.get_classroom_id());
    std::string schedule_course_id = comm->IntToString(teacherPlan.get_schedule_course_id());
    std::string teacher_plan_type = comm->IntToString(teacherPlan.get_teacher_plan_type());

    std::string sql = "INSERT INTO teacher_plan(teacher_plan_id,ts_id,teacher_plan_week,classroom_id,schedule_course_id,teacher_plan_content,teacher_plan_type) VALUES('null','"
                      + ts_id + "','"
                      + teacher_plan_week + "','"
                      + classroom_id + "','"
                      + schedule_course_id + "','"
                      + teacherPlan.get_teacher_plan_content() + "','"
                      + teacher_plan_type + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int TeacherPlanDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM teacher_plan WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;

}
int TeacherPlanDAO::updat(TeacherPlan teacherPlan)
{
    common *comm;
    std::string teacher_plan_id = comm->IntToString(teacherPlan.get_teacher_plan_id());
    std::string ts_id = comm->IntToString(teacherPlan.get_ts_id());
    std::string teacher_plan_week = comm->IntToString(teacherPlan.get_teacher_plan_week());
    std::string classroom_id = comm->IntToString(teacherPlan.get_classroom_id());
    std::string schedule_course_id = comm->IntToString(teacherPlan.get_schedule_course_id());
    std::string teacher_plan_type = comm->IntToString(teacherPlan.get_teacher_plan_type());

    std::string sql = "UPDATE teacher_plan SET ts_id = '" + ts_id
                      + "',teacher_plan_week = '" + teacher_plan_week
                      + "', classroom_id = '" + classroom_id
                      + "', schedule_course_id = '" + schedule_course_id
                      + "', teacher_plan_content = '" + teacherPlan.get_teacher_plan_content()
                      + "', teacher_plan_type = '" + teacher_plan_type
                      + "' WHERE teacher_plan_id = '" + teacher_plan_id
                      + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<TeacherPlan> TeacherPlanDAO::find(std::string condition)
{
    ResultSet *res;
    std::list<TeacherPlan> teacherplan_list;

    std::string sql = "SELECT * FROM teacher_plan WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        TeacherPlan *teacherPlan = new TeacherPlan();
        teacherPlan->set_teacher_plan_id(res->getInt("teacher_plan_id"));
        teacherPlan->set_ts_id(res->getInt("ts_id"));
        teacherPlan->set_teacher_plan_week(res->getInt("teacher_plan_week"));
        teacherPlan->set_classroom_id(res->getInt("classroom_id"));
        teacherPlan->set_schedule_course_id(res->getInt("schedule_course_id"));
        teacherPlan->set_teacher_plan_content(res->getString("teacher_plan_content"));
        teacherPlan->set_teacher_plan_type(res->getInt("teacher_plan_type"));

        teacherplan_list.push_back(*teacherPlan);
    }
    return teacherplan_list;
}















