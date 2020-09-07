#include <iostream>
#include <string>
using namespace std;


int main(){
    char letter;
    string sentence;
    //手动将string对象扩容至100, 可以省去读入过程中多次扩展的开销;
    sentence.reserve(100);
    
    while (cin >> letter){
        sentence.push_back(letter);
    }
    
    cout << sentence << endl;

    return 0;
}