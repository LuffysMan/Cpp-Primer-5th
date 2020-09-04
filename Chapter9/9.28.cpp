#include <iostream>
#include <string>
#include <forward_list>
using namespace std;


void insert_after(forward_list<string> &lst_str, const string &str1, const string &str2)
{
    forward_list<string>::iterator prev = lst_str.before_begin();
    forward_list<string>::iterator curr = lst_str.begin();
    while (curr != lst_str.end())
    {
        if (*curr == str1)
        {
            lst_str.insert_after(curr, str2);
            break;
        }
        prev = curr;
        ++curr;
    }
    if (curr == lst_str.end())
    {
        lst_str.insert_after(prev, str2);
    }
}

int main()
{
    forward_list<string> lst_str = {"hello", "you", "but"};
    string str1 = "but";
    string str2 = "has";
    insert_after(lst_str, str1, str2);

    return 0;
}