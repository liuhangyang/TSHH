//
// Created by kiosk on 8/9/16.
//

#include <iostream>
#include "../model/TeaStuPasswd.hpp"
#include "../Util/Common.h"
#include "../server/TeaStuPasswdSrv.h"
#include <list>

int main(int argc,char *argv[])
{

    TeaStuPasswd teaStuPasswd(1,2,"ytingug");
    std::string condition = "ts_passwd_id = 2";
    std::string sql = "SELECT * FROM ts_passwd WHERE "
                      + condition;
    std::cout << sql << std::endl;
    return 0;
}
