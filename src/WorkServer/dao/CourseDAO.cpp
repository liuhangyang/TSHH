//
// Created by yang on 16-8-4.
//

#include "CourseDAO.h"
#include "../model/Course.hpp"
#include <list>
#include "../Util/Common.h"
#include "../Util/DButil.h"

int CourseDAO::insert(Course course)
{
    common *comm;
    std::string dept_id = comm->IntToString(course.get_dept_id());
    std::string sql = "INSERT INTO course(course_id, dept_id, course_name, course_introduction) VALUE('null','"
                      + dept_id + "','"
                      + course.get_course_name() + "','"
                      + course.get_course_introduction() + "')";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int CourseDAO::dele(std::string condition)
{
    std::string sql = "DELETE FROM course WHERE "
                      + condition;
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

int CourseDAO::updat(Course course)
{
    common *comm;
    std::string course_id = comm->IntToString(course.get_course_id());
    std::string dept_id = comm->IntToString(course.get_dept_id());

    std::string sql = "UPDATE course SET dept_id = '" + dept_id
                      + "', course_name = '" + course.get_course_name()
                      + "', course_introduction = '" + course.get_course_introduction()
                      + "' WHERE course_id = '" + course_id + "'";
    DButil *myDB;
    int flag = myDB->runSQLCommand(sql);
    return flag;
}

std::list<Course> CourseDAO::find(std::string condition)
{
    std::list<Course> course_list;
    ResultSet *res;

    std::string sql = "SELECT * FROM course WHERE "
                      + condition;
    DButil *myDB;
    res = myDB->execQuery(sql);
    while(res->next())
    {
        Course *course = new Course();
        course->set_course_id(res->getInt("course_id"));
        course->set_dept_id(res->getInt("dept_id"));
        course->set_course_name(res->getString("course_name"));
        course->set_course_introduction(res->getString("course_introduction"));

        course_list.push_back(*course);
    }
    return course_list;
}