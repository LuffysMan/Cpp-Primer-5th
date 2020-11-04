#include "../Chapter7/7.2.h"


template <typename T>
int compare(const T& t1, const T& t2) {
    if (t1 < t2) 
        return -1;
    else if (t2 < t1) 
        return 1;
    else
        return 0;
}

//报错， error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
int main() {
    compare(Sales_data("cpp", 1, 32), Sales_data("python", 1, 65));
    return 0;
}