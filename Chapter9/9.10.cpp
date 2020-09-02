#include <iostream>
#include <vector>
using std::vector;

int main(){
    vector<int> v1;                             //vector<int>
    const vector<int> v2;                       //const vector<int>
    auto it1 = v1.begin(), it2 = v1.begin();    //vector<int>::iterator
    auto it3 = v1.cbegin(), it4 = v2.cbegin();  //vector<int>::const_iterator
    return 0;
}