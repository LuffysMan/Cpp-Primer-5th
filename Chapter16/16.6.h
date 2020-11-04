template <typename T, unsigned N>
T* begin(const T(&a)[N]) {
    return T+0;
}

template <typename T, unsigned N>
T* begin(const T(&a)[N]) {
    return T+N;
}