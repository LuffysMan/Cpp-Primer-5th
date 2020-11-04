template <typename T, unsigned long N>
constexpr unsigned long size_of_array(const T (&a)[N]) {
    return N;
}