#include <iostream>
#include <vector>
#include <iterator>


int main(){
    std::vector<int> vec = {1,2,3,4,5,6};
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(vec.crbegin(), vec.crend(), out_iter);
    std::cout << std::endl;
    return 0;
}