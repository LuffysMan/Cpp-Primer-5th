#include <iostream>
#include <map>
#include <string>
#include <vector>


int main(){
    std::multimap<std::string, std::string> family;
    std::string xing;
    std::string ming;

    while (std::cin >> xing >> ming){
        family.insert(std::make_pair(xing, ming));
    }

    for (std::map<std::string, std::string>::value_type name: family){
        std::cout << name.first << " " << name.second << std::endl;
    }

    return 0;
}