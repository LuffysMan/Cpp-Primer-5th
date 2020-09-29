#include <iostream>
#include <string>


struct Person{
    std::string get_name() const{return name;}
    std::string get_addr() const{return addr;}

    std::string name;
    std::string addr;
};


std::istream& read(std::istream& is, Person& person){
    is >> person.name >> person.addr;
    return is;
}

std::ostream& print(std::ostream& os, const Person& person){
    os << person.name << " " << person.addr;
    return os;
}