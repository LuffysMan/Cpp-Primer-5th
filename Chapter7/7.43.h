class NoDefault {
public:
    NoDefault (int n) {}
};

class C {
public:
    C(): mem(0) {}

private:
    NoDefault mem;
};