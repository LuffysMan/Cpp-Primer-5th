#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> v = {0,1};
    vector<int>::iterator begin = v.begin();

    while (begin != v.end()){
        ++begin;
        v.insert(begin, 42);                //进行insert操作之后, begin失效, 后续对begin的使用是未知的.
        ++begin;
    }

    return 0;
}
