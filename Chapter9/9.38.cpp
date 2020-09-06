#include <iostream>
#include <vector>
using namespace std;

inline void fill(vector<int> &v){
    while (v.size() != v.capacity()){
        v.push_back(0);
    }
}

inline void enlarge(vector<int> &v){
    v.push_back(0);
}

int main(){
    vector<int> v = {1,2,3};

    // gcc 7.50, 每次扩容翻倍
    for(int k = 0; k<10; ++k){
        int capacity_before_enlarge = v.capacity();
        fill(v);
        enlarge(v);
        int capacity_after_enlarge = v.capacity();
        cout << "before: " << capacity_before_enlarge << " after: " << capacity_after_enlarge <<  endl;
    }

    return 0;
}
