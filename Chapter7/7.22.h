#include <iostream>
#include <string>


struct Person{
friend std::istream& read(std::istream& is, Person& person);
friend std::ostream& print(std::ostream& os, const Person& person);


public:
    Person() = default;
    Person(const std::string& n):name(n){}
    Person(const std::string& n, const std::string& a):name(n),addr(a){}
    Person(std::istream& is){
        is >> name >> addr;
    }

    std::string get_name() const{return name;}
    std::string get_addr() const{return addr;}

private:
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