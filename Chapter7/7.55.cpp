#include <string>
#include <iostream>
#include <type_traits>

struct Data {
    int ival;
    std::string s;
};

//不是字面值常量
int main() {
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl;
    return 0;
}