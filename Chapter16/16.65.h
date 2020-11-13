#include <sstream>
#include <string>
#include <iostream>


template <typename T> std::string debug_rep(const T& t) {
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

template <typename T> std::string debug_rep(T* p) {
    std::ostringstream oss;
    oss << "pointer: " << p;
    if (p) {
        oss << "content" << *p;
    }
    return oss.str();
}

template<>
std::string debug_rep(char* p) {
    std::cout << "char* version" << std::endl;
    return debug_rep(std::string(p));
}

template<>
std::string debug_rep(const char* p) {
    std::cout << "const char* version" << std::endl;
    return debug_rep(std::string(p));
}