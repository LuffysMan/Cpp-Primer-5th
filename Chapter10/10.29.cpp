#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;


int main(){
    ifstream ifs("./10.29.txt");

    vector<string> words;
    istream_iterator<string> in(ifs), eof;

    while (in != eof){
        words.push_back(*in++);
    }

    ostream_iterator<string> out_iter(cout, " ");
    copy(words.begin(), words.end(), out_iter);

    return 0;
}

