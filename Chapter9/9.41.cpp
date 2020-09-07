#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    vector<char> cvec = {'a','b','c'};
    string str1(cvec.begin(), cvec.end());

    cout << str1 << endl;
    
    return 0;
}