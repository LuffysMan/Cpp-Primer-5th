#include <vector>

/*
class Example {
public:
    static double rate = 6.5;               //错误， 非constexpr不能在类内初始化
    static const int vecSize = 20;          //正确
    static vector<double> vec(vecSize);     //错误， 
};

double Example::rate;
vector<double> Example::vec;
*/

//修正
class Example {
public:
    static double rate;               
    static const int vecSize = 20;          //正确
    static std::vector<double> vec;     //错误， 
};

double Example::rate = 6.5;
std::vector<double> Example::vec(Example::vecSize);
