#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::ifstream;
using std::istringstream;


map<string, string> build_transmap(ifstream &map_file){
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)){
        trans_map[key] = value.substr(1);
    }

    return trans_map;
}

string transform(const map<string,string> &trans_map, const string &word){
    map<string, string>::const_iterator citer = trans_map.find(word);
    return (citer == trans_map.cend() ? word : citer->second);
}

void word_transform(ifstream &map_file, ifstream &input){
    map<string, string> trans_map = build_transmap(map_file);
    string text;
    while (std::getline(input, text)){
        istringstream record(text);
        string word;
        while (record >> word){
            cout << transform(trans_map, word) << " ";
        }
        cout << std::endl;
    }
}

int main(){
    std::ifstream map_file("./11.33.map_file.txt");
    std::ifstream input("11.33.input.txt");    

    word_transform(map_file, input);

    return 0;
}