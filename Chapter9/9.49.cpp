#include <iostream>
#include <string>
using namespace std;


inline bool is_ascender_or_descender(const string &word){
    string ascender("bdfhiklt");
    string descender("gjpqy");
    return string::npos != word.find_first_of(ascender) || string::npos != word.find_first_of(descender);
}


int main(){

    string word;
    string word_longest;
    
    while (cin >> word){
        if (!is_ascender_or_descender(word))
            word_longest = word.size()>word_longest.size() ? word : word_longest;
    }

    cout << "The longest word which is not ascender or descender is: " << word_longest << endl;
    return 0;
}