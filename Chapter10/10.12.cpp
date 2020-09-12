#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct Sale_data{
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;

    Sale_data() = default;
    Sale_data(const string &bookNo):bookNo(bookNo){}
    
    string isbn(){
        return bookNo;
    }
};


bool compareIsbn(Sale_data &item1, Sale_data &item2){
    return item1.isbn() < item2.isbn();
}

int main(){
    Sale_data data;
    vector<Sale_data> itemVec;

    itemVec.emplace_back("x-12");
    itemVec.emplace_back("x-10");
    itemVec.emplace_back("x-11");
    itemVec.emplace_back("x-13");
    
    sort(itemVec.begin(), itemVec.end(), compareIsbn);

    return 0;
}