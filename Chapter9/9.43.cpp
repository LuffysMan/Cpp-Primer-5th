#include <iostream>
#include <string>
using namespace std;


void replace(string &s, string &oldVal, string &newVal){
    string::size_type pos = s.find(oldVal);
    if (string::npos != pos){
        string::iterator iter = s.erase(s.begin()+pos, s.begin()+pos+oldVal.size());
        s.insert(iter, newVal.begin(), newVal.end());
    }
}


int main(){
    string s = "tho enough";
    string oldVal("tho");
    string newVal("though");

    cout << s << endl;
    replace(s, oldVal, newVal);
    cout << s << endl;
    return 0;
}