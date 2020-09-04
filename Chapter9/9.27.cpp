#include <iostream>
#include <forward_list>
using namespace std;

int main(){
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    int L = sizeof(ia)/sizeof(int);
    forward_list<int> lst1(ia, ia+L);
    
    forward_list<int>::iterator prev = lst1.before_begin();
    forward_list<int>::iterator curr = lst1.begin();

    while (curr != lst1.end()){
        if (*curr%2){
            curr = lst1.erase_after(prev);
        }
        else{
            prev = curr;
            ++curr;
        }
    }

    return 0;
}