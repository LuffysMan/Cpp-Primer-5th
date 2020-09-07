#include <iostream>
#include <string>
using namespace std;


string combine(const string &name, const string &prefix, const string &suffix){
    string newName;
    newName.append(prefix);
    newName.append(name);
    newName.append(suffix);
    return newName;
}


int main(){
    string name;
    string prefix;
    string suffix;
    cin >> prefix >> name >> suffix;
    cout << combine(name, prefix, suffix) << endl;;
    return 0;
}