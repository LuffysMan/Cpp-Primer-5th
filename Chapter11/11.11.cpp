#include <iostream>
#include <set>

#include "../Chapter1/Sales_item.h"

//使用函数指针来声明类型
int main(){
    std::multiset<Sales_item, bool (*)(const Sales_item &lhs, const Sales_item &rhs)> bookstore(compareIsbn);

    Sales_item item;
    while (std::cin >> item){
        bookstore.insert(item);
    }

    for (Sales_item item: bookstore){
        std::cout << item << std::endl;
    }
    
    return 0;
}