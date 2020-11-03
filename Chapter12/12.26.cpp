#include <memory>
#include <iostream>
#include <string>


void inverse_output(int n) {
    std::allocator<std::string> a;
    std::string* const p = a.allocate(n);
    std::string *q = p;
    std::string word;

    while (std::cin >> word && q != p+n) {
        a.construct(q++, word);
    }

    while (q != p) {
        std::cout << *(--q) << " ";
        a.destroy(q);
    }
    a.deallocate(p, n);
}


int main() {
    inverse_output(5);
    return 0;
}