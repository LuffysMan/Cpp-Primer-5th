#include <iostream>
#include <string>
#include <vector>

template <typename T>
typename std::vector<T>::size_type count(const std::vector<T>& v, const T& t) {
    typename std::vector<T>::size_type n = 0;
    for (typename std::vector<T>::const_iterator citer = v.cbegin(); citer != v.cend(); ++citer) {
        n += *citer == t ? 1 : 0;
    }
    return n;
}


int main() {
    std::vector<double> dvec = {1,2,3,4};
    std::vector<int> nvec = {1,2,3,4};
    std::vector<std::string> svec = {"1","2","3","4"};

    std::cout << count(dvec, 1.0) << std::endl;
    std::cout << count(nvec, 1) << std::endl;
    std::cout << count<std::string>(svec, "1") << std::endl;

    return 0;
}