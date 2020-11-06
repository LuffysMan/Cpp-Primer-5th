#include <iostream>
#include <string>
#include <vector>

typedef std::string::size_type pos;

template <pos H, pos W>
class Screen {
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




