#include "16.16.h"


template <typename T> std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e) {
    T* data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T> void Vec<T>::free() {
    if (elements) {
        for (T* p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T> void Vec<T>::reallocate() {
    size_t newcapacity = size() ? size()*2 : 1;
    std::string* newdata = alloc.allocate(newcapacity);
    std::string* dest = newdata;
    std::string* elem = elements;
    for (size_t i = 0; i < size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T> Vec<T>::Vec(const Vec &t) {
    std::pair<T*, T*> newData = alloc_n_copy(t.elements, t.first_free);
    elements = newData.first;
    first_free = cap = newData.second;
}

template <typename T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    std::pair<T*, T*> newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newData.first;
    first_free = cap = newData.second;
    return *this;
}

template <typename T> Vec<T>::~Vec() {
    free();
}

template <typename T> void Vec<T>::push_back(const T& t) {
    chk_n_alloc();
    alloc.construct(first_free++, t);
}