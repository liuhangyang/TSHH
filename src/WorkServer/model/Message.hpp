//
// Created by yang on 16-8-5.
//

#ifndef TSHH_MESSAGE_HPP
#define TSHH_MESSAGE_HPP

#include <string>
class Message {
public:
    Message() = default;

    ~Message() = default;

    Message(int me_id, int me_ty, int t_id_fr, int t_id_to, std::string me_co, int me_st) {
        this->message_id = me_id;
        this->message_type = me_ty;
        this->ts_id_from = t_id_fr;
        this->ts_id_to = t_id_to;
        this->message_content = me_co;
        this->message_status = me_st;
    }

    /*get方法*/
    int get_message_id()
    {
        return this->message_id;
    }
    int get_message_type()
    {
        return this->message_type;
    }
    int get_ts_id_from()
    {
        return this->ts_id_from;
    }
    int get_ts_id_to()
    {
        return this->ts_id_to;
    }
    std::string get_message_content()
    {
        return this->message_content;
    }
    int get_message_status()
    {
        return this->message_status;
    }

    /*set方法*/
    void set_message_id(int me_id)
    {
        this->message_id = me_id;
    }
    void set_message_type(int me_ty)
    {
        this->message_type = me_ty;
    }
    void set_ts_id_from(int t_id_fr)
    {
        this->ts_id_from = t_id_fr;
    }
    void set_ts_id_to(int t_id_to)
    {
        this->ts_id_to = t_id_to;
    }
    void set_message_content(std::string me_co)
    {
        this->message_content = me_co;
    }
    void set_message_status(int me_st)
    {
        this->message_status = me_st;
    }

private:
    int message_id;     /*主键*/
    int message_type;   /*0：公告 1:回答问题 2:私信   外键*/
    int ts_id_from;     /*消息来源*/
    int ts_id_to;       /*消息目的*/
    std::string message_content;    /*消息内容*/
    int message_status;  /*消息状态0:未读1:已读*/
};


#endif //TSHH_MESSAGE_HPP
