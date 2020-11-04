#include <iostream>

template <typename T, unsigned N>
void print(const T (&a)[N]) {
    for (const T& e: a) {
        std::cout << e << std::endl;
    }
}