//
// Created by yang on 16-8-5.
//

#include "MessageSrv.h"
#include "../model/Message.hpp"
#include <list>

int MessageSrv::add(Message message)
{
    return messageDAO->insert(message);
}

int MessageSrv::delet(std::string condition)
{
    return messageDAO->dele(condition);
}

int MessageSrv::update(Message message)
{
    return messageDAO->updat(message);
}

std::list<Message> MessageSrv::inquire(Message message)
{
    return messageDAO->find(message);
}