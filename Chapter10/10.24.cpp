#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;


bool check_size(int n, string::size_type sz){
    return n > sz;
}


int main(){
    vector<int> v = {1,2,3,4,5,6};
    string word = "hello";
    vector<int>::iterator it_first = find_if(v.begin(), v.end(), bind(check_size, placeholders::_1, word.size()));
    cout << *it_first << endl;
    return 0;
}