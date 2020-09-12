#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//去重
void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    vector<string>::iterator unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}


void biggies(vector<string> &words, vector<string>::size_type sz){
    //去重
    elimDups(words);
    //将长度大于等于sz的元素放到容器前部
    vector<string>::iterator sz_end = partition(words.begin(), words.end(), [sz](const string &s){return s.size()>=sz;});
    //输出
    for_each(words.begin(), sz_end, [](const string &s){cout << s << " ";});
    cout << endl;
}


int main(){
    vector<string> words = {"hello", "suzy", "diner?", "bye"};
    biggies(words, 5);
    return 0;
}