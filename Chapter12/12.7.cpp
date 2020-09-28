#include <iostream>
#include <vector>
#include <memory>


std::shared_ptr<std::vector<int>> foo(){
    std::shared_ptr<std::vector<int>> pVec = std::make_shared<std::vector<int>>(std::vector<int>({1,2,3,4,5}));
    return pVec;
}

void print(std::shared_ptr<std::vector<int>> pVec){
    for (int num: *pVec){
        std::cout << num << std::endl;
    }
}


int main(){
    std::shared_ptr<std::vector<int>> pVec = foo();
    print(pVec);

    return 0;
}