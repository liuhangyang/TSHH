//
// Created by yang on 16-8-5.
//

#ifndef TSHH_ANSWER_HPP
#define TSHH_ANSWER_HPP


#include <string>

class AnsWer {
public:
    AnsWer() = default;
    ~AnsWer() = default;
    AnsWer(int as_id,int t_id,int q_id,std::string as_con) {
        answer_id = as_id;
        ts_id = t_id;
        question_id = q_id;
        answer_content = as_con;
    }

    /*set 方法 */
    void set_answer_id(int as_id) {
        answer_id = as_id;
    }
    void set_ts_id(int t_id) {
        ts_id = t_id;
    }
    void set_question_id(int q_id) {
        question_id = q_id;
    }
    void set_answer_content(std::string as_con) {
        answer_content = as_con;
    }

    /*get 方法*/
    int get_answer_id() {
        return answer_id;
    }
    int get_ts_id() {
        return ts_id;
    }
    int get_question_id() {
        return question_id;
    }
    std::string get_answer_content() {
        return answer_content;
    }

private:
    int answer_id;                       //主键
    int ts_id;                           //回答者ID
    int question_id;                     //问题ID
    std::string answer_content;          //答案内容
};


#endif //TSHH_ANSWER_HPP
