#include <unordered_set>
#include <string>

#include "../Chapter1/Sales_item.h"

using std::hash;
using std::string;
using std::unordered_multiset;


size_t hasher(const Sales_item &sd){
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_item &lhs, Sales_item &rhs){
    return lhs.isbn() == rhs.isbn();
}


int main(){
    using SD_multiset = unordered_multiset<Sales_item, decltype(hasher)*, decltype(eqOp)*>;
    SD_multiset bookstore(42, hasher, eqOp);
    return 0;
}