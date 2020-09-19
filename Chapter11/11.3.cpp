#include <iostream>
#include <string>
#include <map>


int main(){
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word){
        ++word_count[word];
    }
    
    for (std::map<std::string, size_t>::value_type wc: word_count){
        std::cout << wc.first << " occurs " << wc.second << (wc.second > 1 ? " times " : "time") << std::endl;
    }

    return 0;
}