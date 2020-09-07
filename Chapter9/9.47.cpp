#include <iostream>
#include <string>
using namespace std;


int main(){
    string name = "ab2c3d7R4E6";

    string numbers = "0123456789";
    string letters;
    for (char c='a'; c<='z'; ++c){
        letters.push_back(c);
    }
    for (char c='A'; c<='Z'; ++c){
        letters.push_back(c);
    }

    string::size_type pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos){
        cout << "found number at index: " << pos << " element is " << name[pos] << endl;
        ++pos;
    }

    pos = 0;
    while ((pos = name.find_first_not_of(letters, pos)) != string::npos){
        cout << "found number at index: " << pos << " element is " << name[pos] << endl;
        ++pos;
    }

    pos = 0;
    while ((pos = name.find_first_of(letters, pos)) != string::npos){
        cout << "found letter at index: " << pos << " element is " << name[pos] << endl;
        ++pos;
    }

    pos = 0;
    while ((pos = name.find_first_not_of(numbers, pos)) != string::npos){
        cout << "found letter at index: " << pos << " element is " << name[pos] << endl;
        ++pos;
    }

    return 0;
}
