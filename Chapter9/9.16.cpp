#include <iostream>
#include <vector>
#include <list>

using namespace std;


int main(){
    vector<int> v1 = {1,2,3};
    list<long> lst1 = {1,2,3,4};
    cout << (v1 < lst1) << endl;
    return 0;
}
