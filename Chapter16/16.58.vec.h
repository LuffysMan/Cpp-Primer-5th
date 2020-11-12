#include <string>
#include <memory>

template <typename T>
class Vec {
public:
    Vec():elements(nullptr), first_free(nullptr), cap(nullptr) { }

    Vec(const Vec &t) {
        std::pair<T*, T*> newData = alloc_n_copy(t.elements, t.first_free);
        elements = newData.first;
        first_free = cap = newData.second;
    }

    Vec &operator=(const Vec& rhs) {
        std::pair<T*, T*> newData = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = newData.first;
        first_free = cap = newData.second;
        return *this;
    }

    ~Vec() {
        free();
    }

    void push_back(const T& t) {
        chk_n_alloc();
        alloc.construct(first_free++, t);
    }

    template <typename... Args> void emplace_back(Args&&... args) {
        chk_n_alloc();
        alloc.construct(first_free++, std::forward<Args>(args)...);
    }
    
    size_t size() const {return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }

private:
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }

    std::pair<T*, T*> alloc_n_copy(const T* b, const T* e) {
        T* data = alloc.allocate(e - b);
        return {data, uninitialized_copy(b, e, data)};
    }

    void free() {
        if (elements) {
            for (T* p = first_free; p != elements; ) {
                alloc.destroy(--p);
            }
            alloc.deallocate(elements, cap - elements);
        }
    }

    void reallocate() {
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

    static std::allocator<T> alloc;
    T* elements;
    T* first_free;
    T* cap;
};