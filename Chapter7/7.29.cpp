#include <iostream>
#include "7.29.h"


int main(){
    Screen myScreen(5, 5, 'X');
    //对原对象执行move操作后， 接下来的set和display都是在新的对象上进行的操作。
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    //还是显示原对象
    myScreen.display(std::cout);
    std::cout << "\n";
}