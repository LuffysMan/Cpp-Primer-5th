#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
虽然vector没有push_front()操纵, 但是可以使用insert()操作来实现类似的功能;
由于vector是顺序存储的, 因此每次在头部插入word, 需要将vector中所有元素后移, 效率比较低;
*/
int main(){
    vector<string> v0;
    vector<string>::iterator iter = v0.begin();
    string word;

    while (cin >> word){
        iter = v0.insert(iter, word);
    }    

    return 0;
}
