#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::ifstream;
using std::istringstream;


map<string, string> build_transmap(ifstream &map_file);

string transform(const map<string,string> &trans_map, const string &word);

void word_transform(ifstream &map_file, ifstream &input);


int main(){
    std::ifstream map_file("./11.36.map_file.txt");
    std::ifstream input("11.36.input.txt");    

    word_transform(map_file, input);

    return 0;
}

/*
如果一行只有一个关键字, 如果不进行处理, 则会将其转换规则置为空;
为了处理这种情况, 在程序中检查这种情况并抛出一个一场;
*/
map<string, string> build_transmap(ifstream &map_file){
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)){
        if (value.size()>1){
            trans_map[key] = value.substr(1);
        }else{
            throw std::runtime_error("no rule for key "+key);
        }
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