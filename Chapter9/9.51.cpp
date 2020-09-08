#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#include "test.h"

map<string, unsigned int> fullname_month_to_number = {
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"Octomber", 10},
    {"November", 11},
    {"December", 12},
};

map<string, unsigned int> shortname_month_to_number = {
    {"Jan", 1},
    {"Feb", 2},
    {"Mar", 3},
    {"Apr", 4},
    {"May", 5},
    {"Jun", 6},
    {"Jul", 7},
    {"Aug", 8},
    {"Sep", 9},
    {"Oct", 10},
    {"Nov", 11},
    {"Dec", 12},
};


class Date
{
public:
    Date():year(0),month(0),day(0){}
    Date(const string &date_str)
    {
        vector<string> elements;
        if (date_str.find(' ', 0) != string::npos){
            split(date_str, ' ', elements);
        }else if (date_str.find('/', 0) != string::npos){
            split(date_str, '/', elements);
        }else{
            elements.assign({"0","0","0"});
        }
        
        if (fullname_month_to_number.count(elements[0])){
            month = fullname_month_to_number[elements[0]];
        }else if(shortname_month_to_number.count(elements[0])){
            month = shortname_month_to_number[elements[0]];
        }else{
            month = stoul(elements[0]);
        }
        day = stoul(elements[1]);
        year = stoul(elements[2]);

    }
public:
    void split(const string &date_str, const char sep, vector<string> &elements);

public:
    friend ostream &operator<<(ostream &out, const Date &date);
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

ostream &operator<<(ostream &out, const Date &date)
{
    return (out << date.year << " " << date.month << " " << date.day << endl);
}

void Date::split(const string &date_str, const char sep, vector<string> &elements){
    string::size_type begin = 0;
    string::size_type end = 0;
    int count = 0;

    while (count < 3 && (end=date_str.find(sep, begin)) != string::npos){
        elements.push_back(date_str.substr(begin, end-begin));
        begin = end + 1;
        count++;
    }
    if (count == 2){
        elements.push_back(date_str.substr(begin));
    }
}


int main()
{
    string date_str;
    getline(cin, date_str);
    
    Date date(date_str);
    cout << date << endl;
    return 0;
}