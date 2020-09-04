#include <iostream>
#include <vector>

using namespace std;

/*
如果两个指定删除范围的迭代器相等, 则不会删除任何元素, 返回的迭代器也和它们相等.
*/
int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();
    vector<int>::iterator it;

    it = v.erase(begin, begin);
    cout << (it == begin) << endl;
    it = v.erase(end, end);
    cout << (it == end) << endl;

    return 0;
}