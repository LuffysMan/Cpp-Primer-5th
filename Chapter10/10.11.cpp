#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


template <typename T>
    void print(const T &t)
    {
        for (typename T::const_iterator it = t.begin(); it != t.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }


bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}


void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    vector<string>::iterator unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}


int main(){
    vector<string> words = {"the", "quick", "red", "fox", "jumps","over", "the", "slow", "red", "turtle"};
    print(words);
    elimDups(words);
    print(words);
    stable_sort(words.begin(), words.end(), isShorter);
    print(words);
    return 0;
}