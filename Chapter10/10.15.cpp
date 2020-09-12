#include <iostream>
#include <vector>
using namespace std;


int main(){
    int a = 10;
    int b = 0;
    cin >> b;
    auto add = [a](int b){return a+b;};
    cout << add(b) << endl;    
    return 0;
}