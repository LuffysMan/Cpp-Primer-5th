#include <iostream>


int main(){
    int month = 9, day = 7;
    std::cout << "int month=9, day=7" << std::endl;
    std::cout << "month: " << month << " day: " << day;
    
    int month = 09, day = 07;                               //compiling error: invalid digit "9" in otcal constant
    std::cout << "int month=09, day=07" << std::endl;
    std::cout << "month: " << month << " day: " << day;
    
    return 0;
}