#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main(){
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec;

    while (in_iter != eof){
        vec.push_back(*in_iter++);
    }

    sort(vec.begin(), vec.end());

    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);

    return 0;
}

