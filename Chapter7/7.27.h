#include <string>
#include <iostream>


class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' ') { }
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) { }
    char get() const { return contents[cursor];};   //隐士内联
    inline char get(pos ht, pos wd) const;          //显式内联
    Screen &move(pos r, pos c);                     //在实现的时候声明为内联
    Screen &set(char ch) {contents[cursor] = ch; return *this;}
    Screen &set(pos r, pos c, char ch) {contents[r*width+c] = ch; return *this;}
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const { os << contents;}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

char Screen::get(pos ht, pos wd) const {
    return contents[ht*width+wd];
}

inline Screen &Screen::move(pos r, pos c){
    cursor = r*width + c;
    return *this;
}