#include <iostream>
#include <map>
#include <set>
#include <string>


int main(){
    std::multimap<std::string, std::string> pieces = {{"Newton", "mechanics"}, {"Newton", "calculus"}, {"Howking", "blackhole"}};
    std::map<std::string, std::set<std::string>> ordered_pieces;

    for (std::multimap<std::string, std::string>::value_type &piece: pieces){
        ordered_pieces[piece.first].insert(piece.second);
    }

    for (const std::map<std::string, std::set<std::string>>::value_type &author_pieces: ordered_pieces){
        std::cout << author_pieces.first << ": ";
        for (const std::set<std::string>::value_type &piece: author_pieces.second){
            std::cout << piece << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}