#include <iostream>

int main(){
    std::cout << "(a) " << " 'a': char, L'a': wchar_t , " "\"a\": string, L\"a\": wide string" << std::endl;
    std::cout << "(b) " << " 10: integer, 10u: unsigned integer, 10L: long integer, 012: octal integer, 0xC: hexadecimal integer" << std::endl;
    std::cout << "(c) " << " 3.14: double, 3.14f: float, 3.14L: long double" << std::endl;
    std::cout << "(d) " << " 10: integer, 10u: unsigned integer, 10.: double, 10e-2: double" << std::endl;
    return 0;
}