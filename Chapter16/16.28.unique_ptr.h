#include <utility>
#include <cstddef>


class Delete {
    template <typename T> void operator()(T *p) const{
        delete p;
    }
};

template <typename T, typename D = Delete>
class unique_ptr {
public:
    unique_ptr(const T *ptr=nullptr, const D& d=Delete()):__ptr(ptr), __deleter(d) { }
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    unique_ptr(unique_ptr && other):__ptr(other.__ptr), __deleter(std::move(other.__deleter)) {
        other.__ptr=nullptr;
    }

    unique_ptr& operator=(const unique_ptr&& other) {
        if (__ptr != other.__ptr) {
            reset();
            __ptr = other.__ptr;
            __deleter = std::move(other.__deleter);
            other.__ptr = nullptr;
        }
    }

    unique_ptr& operator=(std::nullptr_t) noexcept {
        reset();
        return *this;
    }

    T* release() noexcept {
        T* ret = __ptr;
        __ptr = nullptr;
        return ret;
    }
    
    void reset(T *ptr=nullptr) noexcept{
        __deleter(__ptr);
        __ptr = ptr;
    }

    void swap(unique_ptr& rhs) noexcept{
        std::swap(__ptr, rhs.__ptr);
        std::swap(__deleter, rhs.__deleter);
    }

    T* get() const noexcept { return __ptr; }
    D& get_deleter() noexcept { return __deleter; }
    const D& get_deleter() const noexcept { return __deleter; }
    explicit operator bool() const noexcept { return __ptr != nullptr; }
    T& operator*() const { return *__ptr; }
    T* operator->() const { return __ptr; }
    T& operator[](size_t i) const { return __ptr[i]; } 

private:
    T *__ptr = nullptr;
    D __deleter = nullptr;
};