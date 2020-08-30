#include <iostream>

int main(){
    std::cout << "(a) Who goes with F\\145rgus?\\012: " << " type: string literal " << "value: "
     << "Who goes with F\145rgus?\012" <<  std::endl;       //Who goes with Fergus?newline
    std::cout << "(b) 3.14e1L: " << " type: " << " long double " << " value: " << 3.14e1L << std::endl;
    std::cout << "(c) 1024f: " << " type: " << " float " << " value " << 1024f << std::endl;
    std::cout << "(d) 3.14L: " << "type: " << " long double " << " value " << 3.14L << std::endl;
    return 0;
}