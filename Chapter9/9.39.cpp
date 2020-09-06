#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    vector<string> svec;       //创建一个元素类型为string的空vector容器
    svec.reserve(1024);         //将svec扩容至1024
    string word;

    //读入未知数量字符串, 放入svec
    while (cin>>word){
        svec.push_back(word);
    }
    svec.resize(svec.size()+svec.size()/2);     //将svec的大小调整为1.5倍, 新增的元素为空字符串
    return 0;
}