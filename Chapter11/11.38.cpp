#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <string>


using std::string;
using std::hash;
using std::unordered_multiset;
using std::unordered_map;
using std::ifstream;
using std::istringstream;
using std::cin;
using std::cout;


void count_word();
void word_transform(ifstream &map_file, ifstream &input);


int main(){
    cout << "-------re-implement of exercise-11.3(word count): " << std::endl;
    count_word();

    cout << "-------re-implement of exercise-11.33(wordtransform): " << std::endl;
    std::ifstream map_file("./11.33.map_file.txt");
    std::ifstream input("11.33.input.txt");    
    word_transform(map_file, input);

    return 0;
}


//单词计数程序
void count_word(){
    using S_umap = unordered_map<string, size_t>;
    S_umap word_count;
    // std::map<std::string, size_t> word_count;
    string sz_input = "the fox deceit the crowl into crying";
    string word;
    std::istringstream isstream(sz_input);
    while (isstream >> word){
        ++word_count[word];
    }
    
    for (S_umap::value_type wc: word_count){
        std::cout << wc.first << " occurs " << wc.second << (wc.second > 1 ? " times " : "time") << std::endl;
    }

}


//单词转换程序
unordered_map<string, string> build_transmap(ifstream &map_file){
    unordered_map<string, string> trans_map;
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

string transform(const unordered_map<string,string> &trans_map, const string &word){
    unordered_map<string, string>::const_iterator citer = trans_map.find(word);
    return (citer == trans_map.cend() ? word : citer->second);
}

void word_transform(ifstream &map_file, ifstream &input){
    unordered_map<string, string> trans_map = build_transmap(map_file);
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

