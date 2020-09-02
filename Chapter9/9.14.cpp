#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


int main(){
    list<char*> v1(10);
    vector<string> v2;
    v2.assign(v1.begin(), v1.end());

    return 0;
}
