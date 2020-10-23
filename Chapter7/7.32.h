#include <string>
#include <vector>

class Screen;
class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};


class Screen {
    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) { }
    char get() const { return contents[cursor];};   //隐士内联
    inline char get(pos ht, pos wd) const;          //显式内联
    Screen &move(pos r, pos c);                     //在实现的时候声明为内联

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


void Window_mgr::clear(ScreenIndex i){
    //s是一个Screen的引用， 指向我们想清空的那个屏幕
    Screen &s = screens[i];
    s.contents = std::string(s.height*s.width, ' ');
}


