#include <iostream>
#include <list>
#include <string>
using namespace std;


int main(){
    list<string> words;
    string word;
    
    while (cin >> word){
        words.push_back(word);
    }

    for(list<string>::iterator iter = words.begin(); iter != words.end(); ++iter){
        cout << *iter << endl;
    }
    
    return 0;
}