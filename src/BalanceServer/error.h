//
// Created by kiosk on 8/9/16.
//

#ifndef TSHH_BALANCE_ERROR_H
#define TSHH_BALANCE_ERROR_H

#include <errno.h>
#include <string>
#include <iostream>

class error {
public:

    error() = default;

    error(const std::string errmsg,int errline) {
        msg = errmsg;
        line = errline;
    }

    void show() {
        std::cerr << line << " : ";
        perror(msg.c_str());
    }

    error set(const std::string errmsg, const int errline) {
        msg = errmsg;
        line = errline;
        return *this;
    }
private:
    std::string msg;
    int  line;

};


#endif //TSHH_BALANCE_ERROR_H
