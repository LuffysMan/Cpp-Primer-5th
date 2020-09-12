#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::vector<const char*> szvec0 = {"hello", "hapi", "world"};
    std::vector<const char*> szvec1 = {"hello", "hapi", "world"};
    std::cout << std::equal(szvec0.cbegin(), szvec0.cend(), szvec1.cbegin()) << std::endl;    //输出1, 比较的是字符串字面值常量的地址, 由于都

}