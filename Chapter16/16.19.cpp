#include <iostream>
#include <list>


template <typename T> std::ostream& print(std::ostream& os, const T& t) {
    typename T::const_iterator iter = t.cbegin();
    for (typename T::size_type i = 0; i < t.size(); ++i) {
        std::cout << (*iter++) << " ";
    }
    return os;
} 


int main() {
    std::list<int> lst = {1,3,4,5,6};
    print(std::cout, lst) << std::endl;
}