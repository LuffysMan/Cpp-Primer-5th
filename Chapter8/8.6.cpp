#include <iostream>
#include <fstream>

#include "../Chapter7/7.2.h"


int main(int argc, char*argv[]){
    Sales_data total;
    std::ifstream ifs(argv[1]);
    if (read(ifs, total)) {
        Sales_data trans;
        while (read(ifs, trans)){
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }else{
        std::cerr << "No data?!" << std::endl;
    }

    return 0;
}