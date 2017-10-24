DROP DATABASE if EXISTS TSHH;

CREATE DATABASE TSHH;
USE  TSHH;

DROP TABLE IF EXISTS data_dict;           /*数据字典*/
DROP TABLE IF EXISTS ts;                  /*教师学生信息表*/
DROP TABLE IF EXISTS ts_passwd;           /*教师学生密码表*/
DROP TABLE IF EXISTS teacher_plan;        /*教学计划安排表*/
DROP TABLE IF EXISTS single_class;        /*单个班级表*/
DROP TABLE IF EXISTS big_class;           /*单个班级组成的大班*/
DROP TABLE IF EXISTS big_class_list;      /*每个大班包含的小班*/
DROP TABLE IF EXISTS college;             /*学院*/
DROP TABLE IF EXISTS dept;                /*专业*/
DROP TABLE IF EXISTS course;              /*班级*/
DROP TABLE IF EXISTS schedule_course;     /*课表*/
DROP TABLE IF EXISTS datad;               /*上传的资料*/
DROP TABLE IF EXISTS download;            /*下载的资料*/
DROP TABLE IF EXISTS question;            /*问题*/
DROP TABLE IF EXISTS answer;              /*答案*/
DROP TABLE IF EXISTS message;             /*消息*/
DROP TABLE IF EXISTS rollcall;            /*点名记录*/
DROP TABLE IF EXISTS rollcall_nothere;    /*点名不在的人*/
DROP TABLE IF EXISTS classroom;           /*教室的地图*/



CREATE TABLE data_dict (
   dict_id              INT NOT NULL AUTO_INCREMENT,  /*主键*/
   dict_parent_id       INT,                          /*父ID*/
   dict_index           INT,                          /*子ID*/
   dict_name            VARCHAR(200),                 /*名字*/
   dict_value           VARCHAR(100) NOT NULL ,        /*值*/
   PRIMARY KEY (dict_id)
);

/*教师学生信息表*/
CREATE TABLE ts (
  ts_id                 INT NOT NULL AUTO_INCREMENT,  /*主键*/
  ts_num                VARCHAR(20),                  /*老师教工号/学生学号*/
  ts_name               VARCHAR(20),                  /*姓名*/
  college_id            INT,                          /*所在学院                              外键*/
  dept_id               INT,                          /*所在系                                外键*/
  single_class_id       INT,                          /*学生的所在班级                         外键*/
  ts_introduction       VARCHAR(200),                 /*自我介绍*/
  ts_head_image         LONGBLOB,                     /*头像*/
  PRIMARY KEY (ts_id)
);

/*教师学生密码表*/
CREATE TABLE ts_passwd (
  ts_passwd_id           INT NOT NULL AUTO_INCREMENT, /*主键*/
  ts_id                  INT,                         /*老师学生ID                              外键*/
  ts_passwd_content      CHAR(32),                    /*密码*/
  PRIMARY KEY (ts_passwd_id)
);

/*教学计划安排表*/
CREATE TABLE teacher_plan (
  teacher_plan_id         INT NOT NULL AUTO_INCREMENT, /*主键*/
  ts_id                   INT,                         /*老师ID                                 外键*/
  teacher_plan_week       INT,                         /*周                                     外键*/
  classroom_id            INT,                         /*确定教室                                外键*/
  schedule_course_id      INT,                         /*确定哪一节课                             外键*/
  teacher_plan_content    VARCHAR(1000),               /*安排的上课内容，预习内容*/
  teacher_plan_type       INT,                         /* 0:上课 1：实验 2：上机  外键             外键*/
  PRIMARY KEY (teacher_plan_id)
);

/*单个班级表*/
CREATE TABLE single_class (
  single_class_id         INT NOT NULL AUTO_INCREMENT,  /*主键*/
  single_class_name       VARCHAR(20),                  /*班级名称 eg:1404*/
  single_class_num        INT,                          /*班级人数  */
  dept_id                 INT,                          /*所在系                   外键*/
  college_id              INT ,                         /*所在学院                 外键*/
  PRIMARY KEY (single_class_id)
);

/*单个班级组成的大班*/
CREATE TABLE big_class (
  big_class_id            INT NOT NULL AUTO_INCREMENT,  /*主键*/
  big_class_name          VARCHAR(40),                  /*大班名称 */
  big_class_people_num    INT,                          /*总人数*/
  ts_id                   INT,                          /*老师ID                   外键*/
  course_id               INT,                          /*课程ID                   外键*/
  PRIMARY KEY (big_class_id)
);


/*大班列表    张根*/
CREATE TABLE big_class_list (
  big_class_id            INT,                            /*大班ID               外键*/
  single_class_id         INT,                            /*小班ID               外键*/
  PRIMARY KEY (big_class_id, single_class_id)
);

/*学院*/
CREATE TABLE college (
  college_id              INT NOT NULL AUTO_INCREMENT,  /*主键*/
  college_name            VARCHAR(20),                  /*学院名称*/
  college_introduction    VARCHAR(1000) ,               /*学院介绍*/
  PRIMARY KEY (college_id)
);


/*专业*/
CREATE TABLE dept (
  dept_id                 INT NOT NULL AUTO_INCREMENT, /*主键*/
  college_id              INT,                         /*属于的学院                        外键*/
  dept_name               VARCHAR(20),                 /*专业名称*/
  dept_introduction       VARCHAR(1000) ,              /*专业介绍*/
  PRIMARY KEY (dept_id)
);

/*课*/
CREATE TABLE course (
  course_id               INT NOT NULL AUTO_INCREMENT, /*主键*/
  dept_id                 INT,                         /*属于的系                           外键*/
  course_name             VARCHAR(20),                 /*课程名*/
  course_introduction     VARCHAR(1000) ,              /*课程介绍*/
  PRIMARY KEY (course_id)
);

/*课表*/
CREATE TABLE schedule_course (
  schedule_course_id      INT NOT NULL AUTO_INCREMENT,  /*主键*/
  dept_id                 INT,                          /*属于的系                              外键*/
  single_class_id         INT,                          /*属于的班级                            外键*/
  schedule_course_day     INT,                          /*1-7 分别表示周一到周天                 外键*/
  schedule_course_course  INT,                          /*1-4 分别标识每天1-4节课                外键*/
  classroom_id            INT,                          /*确定每一个教室                         外键*/
  course_id               INT,                          /*课程                                 外键*/
  PRIMARY KEY (schedule_course_id)
);

/*上传的资料*/
CREATE TABLE datad (
  datad_id                INT NOT NULL AUTO_INCREMENT,                           /*主键*/
  ts_id                   INT,                                                   /*老师/学生ID               外键*/
  course_id               INT,                                                   /*资料分类                  外键*/
  datad_uploadtime        TIMESTAMP DEFAULT CURRENT_TIMESTAMP,                   /*资料上传时间*/
  datad_size              INT,                                                   /*资料大小*/
  datad_content           VARCHAR(200),                                          /*资料的路径*/
  datad_downloadtimes     INT,                                                   /*下载次数*/
  PRIMARY KEY (datad_id)
);

/*下载的资料*/
CREATE TABLE download (
  download_id             INT NOT NULL AUTO_INCREMENT,                            /*主键*/
  datad_id                INT,                                                    /*确定资料             外键*/
  ts_id                   INT,                                                    /*谁下载的             外键*/
  download_time           TIMESTAMP DEFAULT CURRENT_TIMESTAMP,                    /*下载时间*/
  PRIMARY KEY (download_id)
);

/*问题*/
CREATE TABLE question (
  question_id             INT NOT NULL AUTO_INCREMENT,                            /*主键*/
  ts_id                   INT,                                                    /*提问者               外键*/
  question_ask_time       TIMESTAMP DEFAULT CURRENT_TIMESTAMP,                    /*问题的提出时间*/
  question_content        VARCHAR(500),                                           /*问题的内容*/
  question_answertimes    INT,                                                    /*问题的回答个数*/
  course_id               INT,                                                    /*课程ID：问题类型      外键 */
  big_class_id            INT,                                                    /*问题提出的大班ID      外键*/
  PRIMARY KEY (question_id)
);


/*答案*/
CREATE TABLE answer (
  answer_id               INT NOT NULL AUTO_INCREMENT,                             /*主键*/
  ts_id                   INT,                                                     /*回答者的ID               外键*/
  question_id             INT,                                                     /*问题ID                   外键*/
  answer_content          VARCHAR(1000),                                           /*答案内容*/
  answer_time             TIMESTAMP DEFAULT CURRENT_TIMESTAMP,                     /*问题回答时间*/
  PRIMARY KEY (answer_id)
);


/*消息*/
CREATE TABLE message (
  message_id              INT NOT NULL AUTO_INCREMENT,           /*主键*/
  message_type            INT,                                   /*0：公告 1：回答问题 2:私信             外键*/
  ts_id_from              INT,                                   /*消息来源                              外键*/
  ts_id_to                INT,                                   /*消息目的                              外键*/
  message_content         VARCHAR(200),                          /*消息内容*/
  message_status          INT,                                  /*0：未读 1：已读                        外键*/
  message_time            TIMESTAMP DEFAULT CURRENT_TIMESTAMP,   /*消息的发送时间*/
  PRIMARY KEY (message_id)
);

/*点名记录*/
CREATE TABLE rollcall (
  rollcall_id             INT NOT NULL AUTO_INCREMENT, /*主键*/
  rollcall_week           INT,                         /*周                                              外键*/
  schedule_course_id      INT,                         /*确定哪一节课                                     外键*/
  big_class_id            INT,                         /*大班的ID                                        外键*/
  ts_id                   INT,                         /*老师的ID                                        外键*/
  rollcall_yes            INT,                         /*到的人数 */
  rollcall_no             INT,                         /*未到的人数 总人数-到了的人数*/
  PRIMARY KEY (rollcall_id)
);

/*点名不在的人*/
CREATE TABLE rollcall_nothere (
  rollcall_nothere_id     INT NOT NULL AUTO_INCREMENT, /*主键*/
  rollcall_id             INT,                         /*点名ID                                          外键*/
  ts_id                   INT,                          /*学生ID                                         外键 */
  rollcall_nothere_type   INT,                          /*未到状态 -1:缺勤 -2:迟到                         */
  PRIMARY KEY (rollcall_nothere_id)
);

/*教室的地图*/
CREATE TABLE classroom (
  classroom_id            INT NOT NULL AUTO_INCREMENT, /*主键*/
  classroom_name          VARCHAR(20),                 /*教室名称*/
  classroom_way           VARCHAR(200),               /*教室路径*/
  PRIMARY KEY (classroom_id)
);

/*数据字典*/
/*数据字典中的父ID依赖子ID*/
alter table data_dict add constraint FK_super_child_dict foreign key (dict_parent_id)
      references data_dict (dict_id) on delete restrict on update restrict;


/*教师学生信息表*/
/*ts表中的colleg_id依赖于college表中的college_id*/
alter table  ts add constraint FK_ts_college foreign key (college_id)
      references college (college_id) on delete restrict on update restrict;

/*ts表中的dept_id依赖于dept表中的dept_id*/
alter table  ts add constraint FK_ts_dept foreign key (dept_id)
      references dept (dept_id) on delete restrict on update restrict;

/*ts表中的single_class_id依赖于single_class表中的single_class_id*/
alter table  ts add constraint FK_ts_single_class foreign key (single_class_id)
      references single_class (single_class_id) on delete restrict on update restrict;


/*教师学生密码表*/
/*ts_passwd表中的ts_id依赖于ts表中的ts_id*/
alter table  ts_passwd add constraint FK_ts_passwd_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;


/*教学计划安排表*/
/*teacher_plan表中的ts_id依赖于ts表中的ts_id*/
alter table  teacher_plan add constraint FK_teacher_plan_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;

/*teacher_plan表中的teacher_plan_week依赖于data_dict表中的dict_id*/
alter table  teacher_plan add constraint FK_teacher_plan_dict_week foreign key (teacher_plan_week)
      references data_dict (dict_id) on delete restrict on update restrict;

/*teacher_plan表中的classroom_id依赖于data_dict表中的dict_id*/
alter table  teacher_plan add constraint FK_teacher_plan_dict_classroom foreign key (classroom_id)
      references data_dict (dict_id) on delete restrict on update restrict;

/*teacher_plan表中的schedule_course_id依赖于schedule_course表中的schedule_course_id*/
alter table  teacher_plan add constraint FK_teacher_plan_schedule foreign key (schedule_course_id)
      references schedule_course (schedule_course_id) on delete restrict on update restrict;

/*teacher_plan表中的teacher_plan_type依赖于data_dict表中的dict_id*/
alter table  teacher_plan add constraint FK_teacher_plan_dict_class_type foreign key (teacher_plan_type)
      references data_dict (dict_id) on delete restrict on update restrict;


/*单个班级表*/
/*single_class表中的dept_id依赖于dept表中的dept_id*/
alter table  single_class add constraint FK_single_class_dept foreign key (dept_id)
      references dept (dept_id) on delete restrict on update restrict;

/*single_class表中的college_id依赖于college表中的college_id*/
alter table  single_class add constraint FK_single_class_college foreign key (college_id)
      references college (college_id) on delete restrict on update restrict;


/*单个班级组成的大班*/
/*big_class表中的ts_id依赖于ts表中的ts_id*/
alter table  big_class add constraint FK_big_class_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;

/*big_class表中的course_id依赖于course表中的course_id*/
alter table  big_class add constraint FK_big_class_course foreign key (course_id)
      references course (course_id) on delete restrict on update restrict;


/*大班列表*/
/*big_class_list表中的big_class_id依赖于big_class表中的big_class_id*/
alter table  big_class_list add constraint FK_big_class_list_big foreign key (big_class_id)
      references big_class (big_class_id) on delete restrict on update restrict;

/*big_class_list表中的single_class_id依赖于single_class表中的single_class_id*/
alter table  big_class_list add constraint FK_big_class_list_single foreign key (single_class_id)
      references single_class (single_class_id) on delete restrict on update restrict;


/*专业*/
/*dept表中的college_id依赖于college表中的college_id*/
alter table  dept add constraint FK_dept_college foreign key (college_id)
      references college (college_id) on delete restrict on update restrict;

/*课*/
/*course表中的dept_id依赖于dept表中的dept_id*/
alter table  course add constraint FK_course_dept foreign key (dept_id)
      references dept (dept_id) on delete restrict on update restrict;

/*课表*/
/*schedule_course表中的dept_id依赖于dept表中的dept_id*/
alter table  schedule_course add constraint FK_dept_schedule foreign key (dept_id)
      references dept (dept_id) on delete restrict on update restrict;

/*schedule_course表中的single_class_id依赖于single_class表中的single_class_id*/
alter table  schedule_course add constraint FK_schedule_single_class foreign key (single_class_id)
      references single_class (single_class_id) on delete restrict on update restrict;

/*schedule_course表schedule_course_day中的依赖于data_dict表中的dict_id*/
alter table  schedule_course add constraint FK_schedule_dict_schedule_course_day foreign key (schedule_course_day)
      references data_dict (dict_id) on delete restrict on update restrict;

/*schedule_course表schedule_course_course中的依赖于data_dict表中的dict_id*/
alter table  schedule_course add constraint FK_schedule_dict_schedule_course_course foreign key (schedule_course_course)
      references data_dict (dict_id) on delete restrict on update restrict;

/*schedule_course表中的classroom_id依赖于classroom表中的classroom_id*/
alter table  schedule_course add constraint FK_schedule_classroom foreign key (classroom_id)
      references classroom (classroom_id) on delete restrict on update restrict;

/*schedule_course表中的course_id依赖于course表中的course_id*/
alter table  schedule_course add constraint FK_schedule_course foreign key (course_id)
      references course (course_id) on delete restrict on update restrict;


/*上传的资料*/
/*datad表中的ts_id依赖于ts表中的ts_id*/
alter table  datad add constraint FK_datad_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;

/*datad表中的course_id依赖于ts表中的course_id*/
alter table  datad add constraint FK_datad_course foreign key (course_id)
      references course (course_id) on delete restrict on update restrict;


/*下载的资料*/
/*download表中的datad_id依赖于表datad中的datad_id*/
alter table  download add constraint FK_download_datad foreign key (datad_id)
      references datad (datad_id) on delete restrict on update restrict;

/*download表中的ts_id依赖于表ts中的ts_id*/
alter table  download add constraint FK_download_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;


/*问题*/
/*question表中的ts_id依赖于表ts中的ts_id*/
alter table  question add constraint FK_question_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;

/*question表中的course_id依赖于表course中的course_id*/
alter table  question add constraint FK_question_course foreign key (course_id)
      references course (course_id) on delete restrict on update restrict;

/*question表中的big_class_id依赖于表big_class中的big_class_id*/
alter table  question add constraint FK_question_big_class foreign key (big_class_id)
      references big_class (big_class_id) on delete restrict on update restrict;

/*答案*/
/*answer表中的ts_id依赖于表ts中的ts_id*/
alter table  answer add constraint FK_answer_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;

/*answer表中的question_id依赖于表question中的question_id*/
alter table  answer add constraint FK_answer_question foreign key (question_id)
      references question(question_id) on delete restrict on update restrict;

/*消息*/
/* message表中的ts_id_from依赖于表ts中的ts_id*/
alter table  message add constraint FK_message_ts_from foreign key (ts_id_from)
      references ts (ts_id) on delete restrict on update restrict;

/* message表中的ts_id_to依赖于表ts中的ts_id*/
alter table  message add constraint FK_message_ts_to foreign key (ts_id_to)
      references ts (ts_id) on delete restrict on update restrict;

/* message表中的message_type依赖于表data_dict中的dict_id*/
alter table  message add constraint FK_message_data_dict_message_type foreign key (message_type)
      references data_dict (dict_id) on delete restrict on update restrict;

/* message表中的message_status依赖于表data_dict中的dict_id*/
alter table  message add constraint FK_message_data_dict_message_status foreign key (message_status)
      references data_dict (dict_id) on delete restrict on update restrict;

/*点名记录*/
/*rollcall表中的big_class_id依赖于表big_class中的big_class_id*/
alter table  rollcall add constraint FK_rollcall_big_class foreign key (big_class_id)
      references big_class (big_class_id) on delete restrict on update restrict;

/*rollcall表中的ts_id依赖于表ts中的ts_id*/
alter table  rollcall add constraint FK_rollcall_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;

/*rollcall表中的rollcall_week依赖于表data_dict中的dict_id*/
alter table  rollcall add constraint FK_rollcall_data_dict_rollcall_week foreign key (rollcall_week)
      references data_dict (dict_id) on delete restrict on update restrict;


/*点名不在的人*/
/*rollcall_nothere表中的rollcall_id依赖于表rollcall中的rollcall_id*/
alter table  rollcall_nothere add constraint FK_rollcall_nothere_rollcall foreign key (rollcall_id)
      references rollcall (rollcall_id) on delete restrict on update restrict;

/*rollcall_nothere表中的ts_id依赖于表ts中的ts_id*/
alter table  rollcall_nothere add constraint FK_rollcall_nothere_ts foreign key (ts_id)
      references ts (ts_id) on delete restrict on update restrict;




















