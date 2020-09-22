#include <iostream>
#include <set>

#include "../Chapter1/Sales_item.h"


int main(){
    std::multiset<Sales_item, decltype(compareIsbn)*> bookstore(compareIsbn);

    std::multiset<Sales_item, bool (*)(const Sales_item &lhs, const Sales_item &rhs)>::iterator set_it = bookstore.begin();

    return 0;
}
