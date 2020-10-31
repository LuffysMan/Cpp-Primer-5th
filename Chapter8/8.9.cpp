#include <iostream>
#include <sstream>
#include <string>


std::istream& func(std::istream& is){
    std::string word;
    while (is>>word){
        std::cout << word << std::endl;
    }
    is.clear();
    return is;
}


int main(){
    std::string sz = "hello world";
    std::istringstream iss(sz);
    func(iss);
    return 0;
}