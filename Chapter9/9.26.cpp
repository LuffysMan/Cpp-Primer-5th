#include <iostream>
#include <list>
#include <vector>
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
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    int L = sizeof(ia)/sizeof(int);
    vector<int> v(ia, ia+L);
    list<int> lst1(ia, ia+L);
    

    vector<int>::iterator it = v.begin();
    while (it != v.end()){
        if (*it%2 == 0){
            it = v.erase(it);
        }
        else{
            ++it;
        }
    }
    print(v);

    list<int>::iterator iLst = lst1.begin();
    while (iLst != lst1.end()){
        if (*iLst%2 == 0){
            ++iLst;
        }
        else{
            iLst = lst1.erase(iLst);
        }
    }
    print(lst1);

    return 0;
}