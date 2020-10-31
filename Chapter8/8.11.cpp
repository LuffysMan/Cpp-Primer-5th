#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>


struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};


int main(){
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    std::ifstream ifs("8.11.txt");

    while (std::getline(ifs, line)) {
        PersonInfo info;
        record.str(line);               //每次重新加载string即可
        record >> info.name;
        while (record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    return 0;
}
