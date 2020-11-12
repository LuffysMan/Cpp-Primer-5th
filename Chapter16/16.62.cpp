#include <unordered_set>
#include <iostream>

#include "16.62.h"


int main() {
    std::unordered_multiset<Sales_data> multi_set;
    multi_set.emplace("x", 1, 12.0);
    multi_set.emplace("x", 1, 13.0);

    for (const auto& e: multi_set) {
        print(std::cout, e) << " " << std::hash<Sales_data>()(e) << std::endl;
    }    
    return 0;
}