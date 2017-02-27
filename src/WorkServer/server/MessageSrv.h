//
// Created by yang on 16-8-5.
//

#ifndef TSHH_MESSAGE_H
#define TSHH_MESSAGE_H

#include "../model/Message.hpp"
#include "../dao/MessageDAO.h"
#include <list>

class MessageSrv {
public:
    int add(Message message);
    int delet(std::string condition);
    int update(Message message);
    std::list<Message> inquire(Message message);

private:
    MessageDAO *messageDAO = new MessageDAO();
};


#endif //TSHH_MESSAGE_H
