#include <iostream>
#include <deque>
#include <string>
using namespace std;


int main(){
    deque<string> words;
    string word;
    
    while (cin >> word){
        words.push_back(word);
    }

    for(deque<string>::iterator iter = words.begin(); iter != words.end(); ++iter){
        cout << *iter << endl;
    }
    
    return 0;
}