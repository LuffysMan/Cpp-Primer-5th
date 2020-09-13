#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main(){
    vector<int> v = {1,2,2,3,2,2,1};
    sort(v.begin(), v.end());

    list<int> lst;
    unique_copy(v.cbegin(), v.cend(), back_inserter(lst));

    for (int num: lst){
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}