#include <fstream>
#include <iostream>
#include <string>

#include "./12.19.h"


int main() {
    std::ifstream ifs("12.20.txt");
    std::string buf;
    StrBlob blob;

    while (std::getline(ifs, buf)) {
        blob.push_back(buf);
    }

    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend;
         pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
    
    return 0;
}