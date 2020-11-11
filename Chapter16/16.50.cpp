#include <iostream>

//1
template <typename T> void f(T) {
    std::cout << "template1" << std::endl;
}                
template <typename T> void f(const T*) {
    std::cout << "template2" << std::endl;
}
template <typename T> void g(T) {
    std::cout << "template3" << std::endl;
}
template <typename T> void g(T*) {
    std::cout << "template4" << std::endl;
}

int main() {
    
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42);              //type: int(rvalue); call template3; T: int; instatiation: g(int) 
    g(p);               //type: int*; call template4; T: int; instatiation: g(int*) 
    g(ci);              //type: const int; call template3; T: const int; instatiation: g(const int) 
    g(p2);              //type: const int*; call template4; T: const int; instatiation: g(const int*) 
    f(42);              //type: int(rvalue); call template1; T: int; instatiation: f(int) 
    f(p);               //type: int*; call template1; T: int*; instatiation: f(int*);
    f(ci);              //type: const int; call template1; T: const int; instatiation: f(const int)
    f(p2);              //type: const int*; call template2; T: int; instatiation: f(const int*)

    return 0;
}
