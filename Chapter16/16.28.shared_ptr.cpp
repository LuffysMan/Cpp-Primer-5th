#include "16.28.h"

template <typename T>
shared_ptr<T>::shared_ptr(T* ptr, DelFuncPtr del):__ptr(ptr), __count_ptr(new size_t(ptr!=nullptr)), 
__del(del) { }

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr& sp):__ptr(sp.__ptr),__count_ptr(sp.__count_ptr),__del(sp.del) {
    ++*__count_ptr;
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr&& sp) noexcept: shared_ptr() {
    swap(sp);
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr sp) noexcept{
    swap(sp);
}


template <typename T>
shared_ptr<T>::~shared_ptr() {
    if (!__ptr) return;

    if (--*__count_ptr == 0) {
        __del ? __del(__ptr) : delete __ptr;
        delete __count_ptr;
    }
    __ptr = nullptr;
    __count_ptr = nullptr;
}

template <typename T>
void shared_ptr<T>::reset(T* ptr, DelFuncPtr del) {
    shared_ptr tmp(ptr, del);
    swap(tmp);
}

template <typename T>
void shared_ptr<T>::swap(shared_ptr& r) noexcept {
    using std::swap;
    swap(__ptr, r.__ptr);
    swap(__count_ptr, r.__count_ptr);
    swap(__del, r.__del);
}

template <typename T>
T* shared_ptr<T>::get() const noexcept{
    return __ptr;
}

template <typename T>
T& shared_ptr<T>::operator*() const noexcept{
    return *get();
}

template <typename T>
T* shared_ptr<T>::operator->() const noexcept {
    return get();
}

template <typename T>
size_t shared_ptr<T>::use_count() const noexcept {
    return *__count_ptr;
}

template <typename T>
shared_ptr<T>::operator bool() const noexcept {
    return __ptr != nullptr;
}
