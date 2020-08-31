#include <iostream>

int i = 42; // reused has global scope
int main()
{
    int i = 100;
    int j = i;
    std::cout << j << std::endl;

    return 0;
}