#include <cstddef>
#include <utility>

template <typename T>
class shared_ptr {
    using DelFuncPtr = void(*)(T*);

public:
    shared_ptr(T* ptr=nullptr, DelFuncPtr del=nullptr);
    shared_ptr(const shared_ptr&);
    shared_ptr(const shared_ptr&&) noexcept;
    shared_ptr& operator=(shared_ptr) noexcept;
    ~shared_ptr();

    void reset(T* ptr=nullptr, DelFuncPtr del=nullptr);
    void swap(shared_ptr& sp) noexcept;

    T* get() const noexcept;
    T& operator*() const noexcept;
    T* operator->() const noexcept;
    size_t use_count() const noexcept;
    explicit operator bool() const noexcept;

private:
    T __ptr = nullptr;
    size_t *__count_ptr = nullptr;
    DelFuncPtr __del = nullptr;
};