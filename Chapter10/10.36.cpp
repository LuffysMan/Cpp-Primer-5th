#include <list>
#include <algorithm>
#include <iostream>

int main(){
    std::list<int> lst = {1,2,0,1,0,11};
    std::list<int>::const_reverse_iterator iter  = find(lst.crbegin(), lst.crend(), 0);
    std::cout << *iter << std::endl;
    return 0;
}