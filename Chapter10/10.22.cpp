#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


bool check_size(const string &s, string::size_type sz){
    return s.size() <= sz;
}


int main(){
    vector<string> words = {"hello", "suzy", "diner?n", "bye"};
    cout << count_if(words.begin(), words.end(), bind(check_size, std::placeholders::_1, 6)) << endl;

    return 0;
}