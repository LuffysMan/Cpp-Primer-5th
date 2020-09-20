#include <iostream>
#include <string>
#include <vector>


int main(){
    std::vector<std::pair<std::string, int>> vec;
    std::string sz_in;
    int num;
    
    while (std::cin >> sz_in >> num){
        vec.emplace_back(std::pair<std::string, int>(sz_in, num));
    }


    return 0;
}