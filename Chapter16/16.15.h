/*将输入输出操作符声明为友元的必要性有两点：
1. 为何不直接声明为成员函数？因为成员函数第一个隐含的参数是this指针， 所以需要声明为外部函数；
2. 一旦声明为外部函数， 需要访问类的私有成员的话， 必须声明为类的友元；
*/

#include <iostream>
#include <string>
#include <vector>

typedef std::string::size_type pos;
template <pos, pos> class Screen;
template <pos H, pos W> std::istream& operator>>(std::istream& , Screen<H, W>&);
template <pos H, pos W> std::ostream& operator<<(std::ostream& , const Screen<H, W>&);

template <pos H, pos W>
class Screen {
    friend std::istream& operator>><H,W>(std::istream& , Screen<H, W>&);
    friend std::ostream& operator<<<H,W>(std::ostream& , const Screen<H, W>&);
public:
    Screen() = default;
    Screen(char c):height(H), width(W), contents(H*W, c) { }

    inline char get() const;
    inline char get(pos r, pos c) const;          
    inline Screen& set(char ch);
    inline Screen& set(pos r, pos c, char ch);
    Screen &move(pos r, pos c);                     //在实现的时候声明为内联

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};




