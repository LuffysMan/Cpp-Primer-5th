#include <iostream>
#include <list>
#include <string>


int main(){
    std::list<std::string> lst_n;
    std::list<std::string>::const_iterator c_it = lst_n.begin();           //读
    std::list<std::string>::reference ref = lst_n.front();                  //写
    return 0;
}