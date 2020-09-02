#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &vec){
   for(auto it = vec.cbegin(); it != vec.end(); ++it){
       cout << *it << " ";
   }
   cout << endl;
}


int main(){
    // 默认初始化
    vector<int> v1;
    cout << "默认初始化: ";
    print(v1);

    // 初始化为同类型对象的拷贝
    v1.push_back(0);
    vector<int> v2(v1);
    vector<int> v3 = v1;
    cout << "拷贝初始化: ";
    print(v2);

    // 使用初始化列表
    vector<int> v4{1,2,3};
    vector<int> v5 = {1,2,3};
    cout << "初始化列表初始化: ";
    print(v4);

    //顺序容器独有的初始化: 接收一个size值和一个元素初始值
    vector<int> v6(10, 1);
    vector<int> v7(10);
    cout << "size + initializer初始化: ";
    print(v7);

    return 0;   
}