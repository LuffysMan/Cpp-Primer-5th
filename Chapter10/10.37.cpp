#include <iostream>
#include <vector>
#include <list>
#include <iterator>


int main(){
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::list<int> lst;
    std::copy(v.crbegin()+2, v.crbegin()+7, std::back_inserter<std::list<int>>(lst));

    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(lst.cbegin(), lst.cend(), out_iter);
    std::cout << std::endl;

    return 0;
}