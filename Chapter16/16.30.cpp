#include <iostream>
#include <string>

#include "16.29.h"


int main() {
    Blob<std::string> strBlob({"hhh", "bbb"});
    for (size_t i = 0; i < strBlob.size(); ++i) {
        std::cout << strBlob[i] << std::endl;
    }

    return 0;
}