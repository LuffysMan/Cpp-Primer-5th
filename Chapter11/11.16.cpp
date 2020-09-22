#include <iostream>
#include <map>
#include <string>


int main(){
    std::map<std::string, int> word_count = {{"hello",1}, {"world",2}};
    std::map<std::string, int>::iterator map_it = word_count.begin();
    std::cout << (map_it->second = 1) << std::endl;;

    return 0;
}