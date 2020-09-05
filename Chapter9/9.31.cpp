#include <iostream>
#include <list>
#include <forward_list>

#include "test.h"

using namespace std;


template <typename T>
    void delete_even_copy_odd(T &container){
        typename T::iterator iter = container.begin();
        while (iter != container.end()){
            if (*iter%2){
                iter = container.insert(iter, *iter);
                iter++;
                iter++;
            }else{
                iter = container.erase(iter);
            }
        }
    }

int main(){
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    print(lst);
    delete_even_copy_odd(lst);
    print(lst);
    return 0;
}
