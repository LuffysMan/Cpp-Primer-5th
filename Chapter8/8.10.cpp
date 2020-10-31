#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


void read(std::string file, std::vector<std::string>& svec){
    std::ifstream ifs(file, std::ios_base::in);
    if (ifs){
        std::string buf;
        while (std::getline(ifs, buf)){
            svec.push_back(buf);
        }
    }
}


int main(){
    std::vector<std::string> svec;
    read("8.10.txt", svec);

    for (const std::string& line: svec){
        std::string word;
        std::istringstream iss(line);
        while (iss >> word){
            std::cout << word << std::endl;
        }
    }

    return 0;
}