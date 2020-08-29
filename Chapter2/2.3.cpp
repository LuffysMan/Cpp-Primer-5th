#include <iostream>

int main(){
    unsigned int u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;       // 32
    std::cout << u - u2 << std::endl;       // 等价于2**32+u-u2 = 4294967264

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;       // 32
    std::cout << i - i2 << std::endl;       // -32

    std::cout << i - u2 << std::endl;       // 4294967264
    std::cout << u2 - i << std::endl;       // 32
    return 0;
}