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

template <>
std::vector<const char*>::size_type count(const std::vector<const char*>& v, const char* const & t) {
    std::vector<const char*>::size_type n = 0;
    for (typename std::vector<const char*>::const_iterator citer = v.cbegin(); citer != v.cend(); ++citer) {
        n += *citer == t ? 1 : 0;
    }
    return n;
}


int main() {
    std::vector<const char*> svec({"hello", "papa", "fruit"});
    const char* p = "hello";
    std::cout << count(svec, p) << std::endl;

    return 0;
}