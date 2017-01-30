//
// Created by kiosk on 8/10/16.
//

#ifndef TSHH_BALANCE_COMMON_HPP
#define TSHH_BALANCE_COMMON_HPP

#include <string>
#include <sstream>


class common {
public:
    common()= default;
    ~common()= default;
    std::string IntToString(int n) {
        std::string str;
        std::stringstream  stream;
        stream << n;
        stream >> str;
        stream.clear();
        return  str;
    }

};


#endif //TSHH_BALANCE_COMMON_HPP
