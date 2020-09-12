#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<string> words = {"hello", "suzy", "diner?n", "bye"};
    cout << count_if(words.begin(), words.end(), [](const string &s){return s.size()>6;}) << endl;

    return 0;
}