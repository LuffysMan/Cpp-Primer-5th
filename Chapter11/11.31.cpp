#include <iostream>
#include <map>
#include <string>


int main(){
    std::multimap<std::string, std::string> pieces = {{"Newton", "wjf"}, {"Newton", "force"}, {"Howking", "Blackhole"}};
    
    std::string author;
    std::multimap<std::string, std::string>::iterator beg = pieces.end(), end = beg;
    while (std::cin >> author){
        beg = pieces.lower_bound(author);
        end = pieces.upper_bound(author);
        pieces.erase(beg, end);
        std::cout << pieces.size() << std::endl;
    }
    return 0;
}