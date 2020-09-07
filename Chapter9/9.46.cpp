#include <iostream>
#include <string>
using namespace std;


string combine(string name, const string &prefix, const string &suffix){
    name.insert(0, prefix);
    name.insert(name.size(), suffix);
    return name;
}


int main(){
    string name;
    string prefix;
    string suffix;
    cin >> prefix >> name >> suffix;
    cout << combine(name, prefix, suffix) << endl;;
    return 0;
}