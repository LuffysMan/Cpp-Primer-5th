#include <sstream>
#include <string>

template <typename T> 
std::string debug_rep(const T& t) {
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

template <typename T>
std::string debug_rep(T *p) {
    std::ostringstream oss;
    oss << p;
    return oss.str();
}