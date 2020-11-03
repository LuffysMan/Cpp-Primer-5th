#include <iostream>
#include <cstring>
#include <string>


char* concat(const char* sz1, const char* sz2) {
    size_t L = strlen(sz1) + strlen(sz2) + 1;
    char* sz = new char[L]();

    strcat(sz, sz1);
    strcat(sz, sz2);
    return sz;
}

char* concat(std::string& str1, std::string& str2){
    char *sz = new char[str1.size() + str2.size() + 1]();
    strcpy(sz, (str1+str2).c_str());
    return sz;
}
int main() {
    std::cout << concat("hello", "wwww") << std::endl;

    std::string str1("biubiu");
    std::string str2("ttt");
    std::cout << concat(str1, str2) << std::endl;
}