#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vi = {1,2,3,4};
    vector<int>::iterator iter = vi.begin();
    cout << vi.capacity() << endl;
    vi.erase(vi.begin());
    cout << vi.capacity() << endl;
    vi.shrink_to_fit();
    cout << vi.capacity() << endl;
    vi.reserve(10);
    cout << vi.capacity() << endl;

    return 0;
}