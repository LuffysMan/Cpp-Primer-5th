#include <iostream>
#include <cstring>


int main() {
    size_t len = 32;
    size_t pos = 0;
    char *buf = new char[len]();
    char ch;

    while (std::cin >> ch) {
        if (pos+1 == len) {
            len *= 2;
            char *tmp = new char[len]();
            strcpy(tmp, buf);
            delete[] buf;
            buf = tmp;
        }
        *(buf+pos) = ch;
        ++pos;
    }

    std::cout << buf << std::endl;

    return 0;
}