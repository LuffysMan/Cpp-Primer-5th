#include <iostream>
#include <string>


std::istream& func(std::istream& is){
    std::string word;
    while (is>>word){
        std::cout << word << std::endl;
    }
    is.clear();
    return is;
}

