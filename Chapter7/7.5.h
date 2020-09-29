#include <string>


struct Person{
    std::string get_name() const{return name;}
    std::string get_addr() const{return addr;}

    std::string name;
    std::string addr;
};