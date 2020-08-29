#include <iostream>
#include <cmath>
#include <string>
#include <climits>

void print_range(size_t bytes, bool is_signed=true){
    size_t bits = 8*bytes;
    std::cout << " size: " << bits;
    if (is_signed){
        std::cout << " min: " << -(1LL<<(bits-1)) << " max: " << ((1LL<<(bits-1))-1) << std::endl;
    }
    else{
        std::cout << " min: " << 0 << " max: " << (1ULL<<bits-1) + ((1ULL<<bits-1)-1) << std::endl;
    }
}

int main(){
    std::cout << "char: ";;
    print_range(sizeof(char));
    std::cout << "unsigned char: ";
    print_range(sizeof(unsigned char), false);
    std::cout << "short int: ";
    print_range(sizeof(short int));
    std::cout << "unsigned short int: ";
    print_range(sizeof(unsigned short int), false);
    std::cout << "int: ";
    print_range(sizeof(int));
    std::cout << "unsigned int: ";
    print_range(sizeof(unsigned int), false);
    std::cout << "long int: ";
    print_range(sizeof(long int));
    std::cout << "unsigned long int: ";
    print_range(sizeof(unsigned long int), false);
    std::cout << "long long int: ";
    print_range(sizeof(long long int));
    std::cout << "unsigned long long int: ";
    print_range(sizeof(unsigned long long int), false);
    std::cout << "float: " << "size: " << sizeof(float) << std::endl;
    std::cout << "double: " << "size: " << sizeof(double) << std::endl;
    std::cout << "long double: " << "size: " << sizeof(long double) << std::endl;
    return 0;
}