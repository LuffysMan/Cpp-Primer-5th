#include <string>


typedef std::string Type;
Type initVal();

class Exercise {
public:
    typedef double DType;
    DType setVal(DType);
    DType initVal() { return 0;}
private:
    int val;
};


Exercise::DType Exercise::setVal(DType parm) {
    val = parm + initVal();
    return val;
}