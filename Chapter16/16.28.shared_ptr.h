#include <cstddef>
#include <utility>

template <typename T>
class shared_ptr {
    using DelFuncPtr = void(*)(T*);

public:
    shared_ptr(T* ptr=nullptr, DelFuncPtr del=nullptr):__ptr(ptr), __count_ptr(new size_t(ptr!=nullptr)),__del(del) { }

    shared_ptr(const shared_ptr& sp):__ptr(sp.__ptr),__count_ptr(sp.__count_ptr),__del(sp.del) {
        ++*__count_ptr;
    }

    shared_ptr(const shared_ptr&& sp) noexcept: shared_ptr() {
        swap(sp);
    }

    shared_ptr& operator=(shared_ptr sp) noexcept{
        swap(sp);
    }

    ~shared_ptr() {
        if (!__ptr) return;

        if (--*__count_ptr == 0) {
            __del ? __del(__ptr) : delete __ptr;
            delete __count_ptr;
        }
        __ptr = nullptr;
        __count_ptr = nullptr;
    }

    void reset(T* ptr, DelFuncPtr del) {
        shared_ptr tmp(ptr, del);
        swap(tmp);
    }

    void swap(shared_ptr& r) noexcept {
        using std::swap;
        swap(__ptr, r.__ptr);
        swap(__count_ptr, r.__count_ptr);
        swap(__del, r.__del);
    }

    T* get() const noexcept{
        return __ptr;
    }

    T& operator*() const noexcept{
        return *get();
    }

    T* operator->() const noexcept {
        return get();
    }

    size_t use_count() const noexcept {
        return *__count_ptr;
    }

    explicit operator bool() const noexcept {
        return __ptr != nullptr;
    }

private:
    T* __ptr = nullptr;
    size_t *__count_ptr = nullptr;
    DelFuncPtr __del = nullptr;
};