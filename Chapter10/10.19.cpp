#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void print_vector(const vector<string>::iterator &cbegin, const vector<string>::iterator &cend){
    for_each(cbegin, cend, [](const string &s){cout << s << " ";});
    cout << endl;
}

//去重
void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    vector<string>::iterator unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}


void bigges(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    vector<string>::iterator wc = stable_partition(words.begin(), words.end(), [sz](const string &a){return a.size() < sz;});
    int count = words.end() - wc;
    cout << count << " words of length " << sz << " or longer" << endl;
    print_vector(wc, words.end());
}


int main()
{
    vector<string> words = {"hello", "helle", "helly", "suzy", "diner", "bye"};
    print_vector(words.begin(), words.end());
    bigges(words, 5);
    return 0;
}