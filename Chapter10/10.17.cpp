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
    
    string isbn()const{
        return bookNo;
    }
};


int main(){
    Sale_data data;
    vector<Sale_data> itemVec;

    itemVec.emplace_back("x-12");
    itemVec.emplace_back("x-10");
    itemVec.emplace_back("x-11");
    itemVec.emplace_back("x-13");
    
    sort(itemVec.begin(), itemVec.end(), [](const Sale_data &item1, const Sale_data &item2){return item1.isbn()<item2.isbn();});
    for_each(itemVec.begin(), itemVec.end(), [](const Sale_data &item){cout << item.isbn() << " ";});
    cout << endl;
    return 0;
}