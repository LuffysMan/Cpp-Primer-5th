#include <iostream>


template <typename T>
std::ostream& print(std::ostream& os, const T& t) {
    return os << t << " ";
}

template <typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... args) {
    os << t << " ";
    return print(os, args...);
}

