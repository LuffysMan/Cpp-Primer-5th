#include <iostream>
#include <vector>
using namespace std;


int main(){
    int some_val = 1;
    vector<int> iv = {1,2,3,4,5,6,7,8,9,10};


    /*
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

    // iter 没有进行自增, 导致循环无法终止
    while (iter != mid){
        if (*iter == some_val){
            //对vector, deque, string等顺序容器进行insert操作后, 所有指向容器的迭代器,指针和引用全部失效, iter和mid在插入一次后就变得无效;
            iv.insert(iter, 2*some_val);      
        }
    }
    */

    //修改
    vector<int>::difference_type n = iv.size()/2;
    vector<int>::iterator iter = iv.begin();

    while (n){
        if (*iter == some_val){
            iter = iv.insert(iter, 2*some_val);      
            ++iter;
        }
        ++iter;
        --n;
    }

    return 0;
}