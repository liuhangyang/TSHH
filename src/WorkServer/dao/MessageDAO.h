//
// Created by yang on 16-8-4.
//

#ifndef TSHH_MESSAGEDAO_H
#define TSHH_MESSAGEDAO_H

#include "../model/Message.hpp"
#include <list>
class MessageDAO {
public:
    int insert(Message message);

    int dele(std::string condition);

    int updat(Message message);

    std::list<Message> find(std::string condition);
};


#endif //TSHH_MESSAGEDAO_H
