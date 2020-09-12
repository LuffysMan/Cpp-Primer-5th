#include <iostream>
#include <vector>
#include <numeric>


int main(){
    std::vector<double> dvec = {1.1, 1.2, 2.1, 3.1};
    double res = std::accumulate(dvec.begin(), dvec.end(), 0);          //0的字面值是整型, 所以结果是按照整型加法算的, 没有计算小数!
    std::cout << res << std::flush;
}