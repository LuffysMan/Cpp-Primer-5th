#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    vector<string> vec;
    string sz_in;
    string target;
    
    while (cin>>target){
        while (cin >> sz_in){
            vec.push_back(sz_in);
        }
    }

    cout << count(vec.cbegin(), vec.cend(), target) << endl;

}