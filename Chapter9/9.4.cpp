#include <iostream>
#include <vector>

bool find(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target){
    while(begin != end){
        if (*begin == target){
            return true;
        }
        ++begin;
    }
    return false;
}


int main(){
    std::vector<int> vec_a(10, 1);
    std::cout << "find 0: " << find(vec_a.begin(), vec_a.end(), 0) << std::endl;
    std::cout << "find 1: " << find(vec_a.begin(), vec_a.end(), 1) << std::endl;
    return 0;
}