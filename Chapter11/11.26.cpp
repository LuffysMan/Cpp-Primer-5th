#include <iostream>
#include <map>
#include <string>

/*
总体来说, 只要进行下标操作的值可以隐式的转化为map的key_type, 就可以进行下标访问; 返回的类型是mapped_type.
*/
int main(){
    std::map<int, std::string> m;
    for (int i = 0; i < 100; ++i)
        m[i] = std::to_string(i);

    //使用各种整型值进行下标操作
    std::cout << "m[1]: " << m[1] << std::endl;
    std::cout << "m[1U]: " << m[1U] << std::endl;
    std::cout << "m[1L]: " << m[1L] << std::endl;
    std::cout << "m[1UL]: " << m[1UL] << std::endl;
    std::cout << "m[1LL]: " << m[1LL] << std::endl;
    std::cout << "m[1ULL]: " << m[1ULL] << std::endl;
    
    //使用浮点数进行下标操作
    std::cout << "m[1.1]: " << m[1.1] << std::endl;
    std::cout << "m[1.1F]: " << m[1.1F] << std::endl;
    std::cout << "m[1.1L]: " << m[1.1L] << std::endl;

    //使用char类型值进行下标操作
    std::cout << "m['a']: " << m['a'] << std::endl;

    //使用bool类型值进行下标操作
    std::cout << "m[true]: " << m[true] << std::endl;
    std::cout << "m[false]: " << m[false] << std::endl;

    //使用字符串字面值常量进行下标操作, 编译器报错, 未重载字符串字面值类型的下标操作符.
    std::cout << "m[\"ab\"]: " << m["ab"] << std::end;

    return 0;
}