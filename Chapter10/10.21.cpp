#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i = 10;
    auto f = [&]()mutable{while (i>0) --i; return i==0;};
    cout << f() << endl;
    cout << f() << endl;
    return 0;
}