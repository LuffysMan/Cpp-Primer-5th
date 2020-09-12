#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main(){
//(a)
#if 0       
    vector<int> vec; list<int> lst; int i;
    while (cin >> i){
        lst.push_back(i);
    }
    // copy(lst.cbegin(), lst.cend(), vec.begin());            //错误! vec是空的, 无法完成拷贝, 修改为back_inserter()即可.
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
#endif

//(b)
#if 1       
    vector<int> vec;
    vec.reserve(10);                            
    fill_n(vec.begin(), 10, 0);       //错误! 虽然reserve将vec的容量扩大到了10以上, 编译和运行都没问题, 但是vec的size并没有变化, 依然是0;
    cout << vec.size() << endl;
#endif

    return 0;
}