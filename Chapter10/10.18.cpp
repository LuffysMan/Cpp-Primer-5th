#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//去重
void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    vector<string>::iterator unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}


void bigges(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    vector<string>::iterator wc = partition(words.begin(), words.end(), [sz](const string &a){return a.size() < sz;});
    int count = words.end() - wc;
    cout << count << " words of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}


int main()
{
    vector<string> words = {"hello", "suzy", "diner?", "bye"};
    bigges(words, 5);
    return 0;
}