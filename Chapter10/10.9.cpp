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


void elimDups(vector<string> &words){
    print(words);
    sort(words.begin(), words.end());
    vector<string>::iterator unique_end = unique(words.begin(), words.end());
    print(words);
    words.erase(unique_end, words.end());
    print(words);
}


int main(){
    vector<string> words = {"the", "quick", "red", "fox", "jumps","over", "the", "slow", "red", "turtle"};
    elimDups(words);
    return 0;
}