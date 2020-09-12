#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool is_longer_than_5(const string &sz){
    return sz.size() >=5;
}


int main(){
    vector<string> vec;
    string word;
    
    while (cin >> word){
        vec.push_back(word);
    }

    vector<string>::iterator find_end = partition(vec.begin(), vec.end(), is_longer_than_5);   
    for (vector<string>::iterator iter = vec.begin(); iter != find_end; ++iter){
        cout << *iter << " ";
    }
    return 0;
}