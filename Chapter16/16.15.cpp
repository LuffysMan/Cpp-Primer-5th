#include "16.14.h"

template <pos H, pos W> std::istream& operator>>(std::istream& is, Screen<H, W>& scr) {
    std::string input;
    is >> input;
    for (char c: input) {
        scr.set(c);
    }
    return is;
}

template <pos H, pos W> std::ostream& operator<<(std::ostream& os, const Screen<H, W>& scr) {
    for (pos r = 0; r != H; ++r) {
        for (pos c = 0; c != W; ++ c) {
            os << scr.get(r,c);
        }
    }
    return os;
}

template <pos H, pos W>
char Screen<H, W>::get() const { 
    return contents[cursor];
}   

template <pos H, pos W>
char Screen<H, W>::get(pos r, pos c) const {
    return contents[r*W+c];
}

template <pos H, pos W>
Screen<H,W>& Screen<H, W>::set(char ch) { 
    contents[cursor++] = ch;
    cursor = std::min(cursor, H*W-1);
    return *this;
}   

template <pos H, pos W>
Screen<H,W>& Screen<H, W>::set(pos r, pos c, char ch) {
    contents[r*W+c] = ch;
    return *this;
}

template <pos H, pos W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c){
    cursor = r*W + c;
    return *this;
}