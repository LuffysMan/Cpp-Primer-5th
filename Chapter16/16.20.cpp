#include <iostream>
#include <list>


template <typename T> std::ostream& print(std::ostream& os, const T& t) {
    for (typename T::const_iterator citer = t.cbegin(); citer != t.cend(); ++citer) {
        std::cout << (*citer) << " ";
    }
    return os;
} 


int main() {
    std::list<int> lst = {1,3,4,5,6};
    print(std::cout, lst) << std::endl;
}