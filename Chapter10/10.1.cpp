#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    vector<int> vec;
    int num;
    int target;
    
    while (cin>>target){
        while (cin >> num){
            vec.push_back(num);
        }
    }

    cout << count(vec.cbegin(), vec.cend(), target) << endl;

}