class X;
class Y;

class X {
    Y *m_y = nullptr;
};

class Y {
    X m_x;
};