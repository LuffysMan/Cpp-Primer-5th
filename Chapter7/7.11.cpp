#include <iostream>
#include <string>

#include "./7.2.h"      //Sales_data类声明和定义


int main(){
    Sales_data item1;
    Sales_data item2("pride and prejudice");
    Sales_data item3("C++Primer5th", 1, 55);
    Sales_data item4(std::cin);
    print(print(print(print(std::cout, item1)<<std::endl, item2)<<std::endl, item3)<<std::endl, item4)<<std::endl;
}