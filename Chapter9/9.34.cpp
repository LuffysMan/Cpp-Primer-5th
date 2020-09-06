#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vi = {1,2,3,4};
    vector<int>::iterator iter = vi.begin();

    //如果数组中存在奇数, 则程序陷入死循环, 一直在第一个奇数前插入相同的奇数.
    while (iter != vi.end()){
        if (*iter%2){
            iter = vi.insert(iter, *iter);
        }
        ++iter;
    }

    return 0;
}