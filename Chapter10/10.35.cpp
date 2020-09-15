#include <iostream>
#include <vector>


int main(){
    std::vector<int> vec = {1,2,3,4,5,6};
    std::vector<int>::const_iterator cend = vec.cend(), cbegin = vec.cbegin();

    while (cend != cbegin){
        std::cout << *(--cend) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}