#include <iostream>
#include <vector>
using namespace std;


int main(){
    auto add = [](int a, int b){return a+b;};
    int a = 0;
    int b = 0;
    cin >> a >> b;
    cout << add(a,b) << endl;    
    return 0;
}