#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>


std::string simplify(std::string& word){
    std::set<char> symbols = {',','.',';',':','?','!'};
    std::string::iterator iter = word.begin();

    while (iter != word.end()){
        if(std::isalpha(*iter)){
            *iter++ |= 32U;
        }else if (symbols.find(*iter) != symbols.end()){
            iter = word.erase(iter);
        } 
    }

    return word;
}

int main(){
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word){
        ++word_count[simplify(word)];
    }
    
    for (std::map<std::string, size_t>::value_type wc: word_count){
        std::cout << wc.first << " occurs " << wc.second << (wc.second > 1 ? " times " : "time") << std::endl;
    }

    return 0;
}