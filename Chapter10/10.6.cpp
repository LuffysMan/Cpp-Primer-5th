#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int a0[] = {1,2,3,4,4,5};
    fill_n(begin(a0), sizeof(a0)/sizeof(int), 0);
    return 0;
}
