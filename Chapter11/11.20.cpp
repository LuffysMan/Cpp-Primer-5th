#include <iostream>
#include <string>
#include <map>

//使用下表操作符更加容易编写和理解
int main(){
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word){
        //使用insert
        ++word_count.insert({word, 0}).first->second;
        //使用下表操作符
        // ++word_count[word];
    }
    
    for (std::map<std::string, size_t>::value_type wc: word_count){
        std::cout << wc.first << " occurs " << wc.second << (wc.second > 1 ? " times " : "time") << std::endl;
    }

    return 0;
}