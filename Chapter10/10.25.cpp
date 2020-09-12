#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


bool check_size(const string &s, string::size_type sz){
    return s.size() < sz;
}

//去重
void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    vector<string>::iterator unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}


void bigges(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    vector<string>::iterator wc = partition(words.begin(), words.end(), bind(check_size, placeholders::_1, sz));
    int count = words.end() - wc;
    cout << count << " words of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}


int main(){
    vector<string> words = {"hello", "suzy", "diner?", "bye"};
    bigges(words, 6);
    return 0;
}