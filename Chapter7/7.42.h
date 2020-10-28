#include <string>


class Employee {
public:
    Employee(std::string nm, unsigned int ag, std::string pos, double sal):name(nm), age(age), position(pos), salary(sal) {}
    Employee():Employee("", 0, "", 0.0) {}
    Employee(std::string nm, std::string pos ):Employee(nm, 0, pos, 0.0) {}

private:
    std::string name;
    unsigned int age = 0;
    std::string position;
    double salary = 0.0;
};