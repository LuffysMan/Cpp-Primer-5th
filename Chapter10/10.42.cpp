#include <iostream>
#include <list>
#include <string>

int main(){
    std::list<std::string> words = {"hello", "fool", "how", "fool", "eat", "the", "fool"};
    
    for(auto word: words){
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    words.sort();
    words.unique();
    for(auto word: words){
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}








