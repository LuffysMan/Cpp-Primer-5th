#include <iostream>

#include "16.56.h"


int main() {
    int i = 1;
    double d = 1.0;
    char c('1');
    bool b = true;
    std::string s("1");
    errorMsg(std::cout, i, d, c, b, s);

    return 0;
}