#include <iostream>
#include <string>
#include <vector>


int main(){
    std::vector<std::pair<std::string, int>> vec;
    std::string sz_in;
    int num;
    
    while (std::cin >> sz_in >> num){
        vec.emplace_back(sz_in, num);                               //最易理解和编写, 而且速度最快, 省去了拷贝的步骤                             
        // vec.push_back({sz_in, num});
        // vec.push_back(std::pair<std::string, int>(sz_in, num));
        // vec.push_back(std::make_pair(sz_in, num));
    }

    for (auto e: vec){
        std::cout << e.first << " " << e.second << std::endl;
    }

    return 0;
}