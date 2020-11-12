#include "16.53.h"


int main() {
    int i = 1;
    double d = 1.0;
    char c('a');
    bool b = true;
    std::string s("hello");

    // print(std::cout, i, d, c, b, s, 42) << std::endl;
    print(std::cout, i, d) << std::endl;

    return 0;
}