#include <iostream>
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
    vector<int> v(25, 1);
    print(v);
    v.resize(100);
    print(v);
    v.resize(10);
    print(v);

    return 0;
}
