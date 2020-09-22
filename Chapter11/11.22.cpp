#include <iostream>
#include <vector>
#include <string>
#include <map>


int main(){
    std::map<std::string, std::vector<int>> family;
   
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret = family.insert({"liu", {1, 2}});
    return 0;
}