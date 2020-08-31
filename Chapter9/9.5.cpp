#include <iostream>
#include <vector>


std::vector<int>::const_iterator find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int target){
    while(begin != end){
        if (*begin == target){
            return begin;
        }
        ++begin;
    }
    return begin;
}

int main(){
    std::vector<int> vec_a(10, 1);
    auto it_find = find(vec_a.cbegin(), vec_a.cend(), 1);
    if (it_find != vec_a.end()){
        std::cout << "find 1: " << *it_find << std::endl;
    }
    return 0;
}
