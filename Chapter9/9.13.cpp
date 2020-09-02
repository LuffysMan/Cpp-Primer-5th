#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main(){
    list<int> lst1 = {1,2,3};
    vector<int> vec1 = {1,2,3};
    
    vector<double> vec2(lst1.cbegin(), lst1.cend());
    vector<int> vec3(vec1);

    return 0;
}
