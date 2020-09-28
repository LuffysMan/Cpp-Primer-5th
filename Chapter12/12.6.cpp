#include <iostream>
#include <vector>


std::vector<int>* foo(){
    std::vector<int>* p = new std::vector<int>({1,2,3,4,5});
    return p;
}

void print(std::vector<int>* pVec){
    for (int num: *pVec){
        std::cout << num << std::endl;
    }
}


int main(){
    std::vector<int>* pVec = foo();
    print(pVec);
    delete pVec;

    return 0;
}