#include <iostream>
#include <vector>
#include <fstream>
#include <string>


void read(std::string file, std::vector<std::string>& svec){
    std::ifstream ifs(file);
    if (ifs){
        std::string buf;
        while (ifs >> buf){
            svec.push_back(buf);
        }    
    }
}


int main(){
    std::vector<std::string> svec;
    read("8.4.txt", svec);

    for(std::string word: svec){
        std::cout << word << std::endl;
    }

    return 0;
}