#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;


template <typename T>
    void print(const T &t)
    {
        for (typename T::const_iterator it = t.begin(); it != t.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }


int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};

    list<int> lst;
    forward_list<int> flst;
    deque<int> que;

    copy(v.cbegin(), v.cend(), back_inserter(lst));
    copy(v.cbegin(), v.cend(), front_inserter(flst));
    copy(v.cbegin(), v.cend(), inserter(que, que.begin()));

    print(lst);
    print(flst);
    print(que);
    
    return 0;
}