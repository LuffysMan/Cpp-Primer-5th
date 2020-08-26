#include <iostream>
#include "Sales_item.h"

int main(){
    Sales_item item, tmp;
    if (std::cin>>item){
        while(std::cin>>tmp){
            item += tmp;
        }
    }
    std::cout << item << std::endl;
    return 0;
}