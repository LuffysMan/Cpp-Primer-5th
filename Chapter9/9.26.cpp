#include <iostream>
#include <list>
#include <vector>
using namespace std;


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

    list<int>::iterator iLst = lst1.begin();
    while (iLst != lst1.end()){
        if (*iLst%2 == 0){
            ++iLst;
        }
        else{
            iLst = lst1.erase(iLst);
        }
    }

    return 0;
}