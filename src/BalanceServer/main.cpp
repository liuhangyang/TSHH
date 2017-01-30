#include <iostream>
#include <fstream>

#include "balance_server.h"

int main() {
    auto s = std::make_shared<balance_server>();
    s->init();
    return 0;

}