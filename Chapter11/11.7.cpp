#include <iostream>
#include <map>
#include <string>
#include <vector>


int main(){
    std::map<std::string, std::vector<std::string>> family;
    std::string xing;
    std::string ming;

    while (std::cin >> xing >> ming){
        family[xing].push_back(ming);
    }

    for (std::map<std::string, std::vector<std::string>>::value_type name: family){
        for (std::string ming: name.second){
            std::cout << name.first << " " << ming << std::endl;
        }
    }

    return 0;
}