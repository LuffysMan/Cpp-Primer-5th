#include <iostream>
#include <vector>
#include <string>
using namespace std;


static inline int sum_of_integers(const vector<string> &svec){
    int cum = 0;
    for (vector<string>::const_iterator citer = svec.cbegin(); citer != svec.cend(); ++citer){
        cum += stoi(*citer);
    }
    return cum;
}


static inline double sum_of_doubles(const vector<string> &svec){
    double cum = 0;
    for (vector<string>::const_iterator citer = svec.cbegin(); citer != svec.cend(); ++citer){
        cum += stod(*citer);
    }
    return cum;
}


int main(){
    vector<string> svec;
    string s_number;
 
    while (cin >> s_number){
        svec.push_back(s_number);
    }

    cout << sum_of_integers(svec) << endl;
    cout << sum_of_doubles(svec) << endl;

    return 0;
}