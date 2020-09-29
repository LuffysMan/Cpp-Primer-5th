#include <memory>
#include <string>

using namespace std;


int main(){
    unique_ptr<string> p1(new string("Stegosaurus"));
    unique_ptr<string> p2(p1);
    /*
    error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]’
     unique_ptr<string> p2(p1);
    */

    return 0;
}