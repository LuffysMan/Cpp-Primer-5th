#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>


int main(){
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> family;
    std::string xing;
    std::string ming;
    std::string birth;

    while (std::cin >> xing >> ming >> birth){
        family[xing].emplace_back(ming, birth);
    }

    for (std::map<std::string, std::vector<std::pair<std::string, std::string>>>::value_type child: family){
        for (std::pair<std::string, std::string> info: child.second){
            std::cout << child.first<< " " << info.first << " " << info.second << std::endl;
        }
    }

    return 0;
}