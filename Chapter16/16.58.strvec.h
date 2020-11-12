#include <string>
#include <memory>


class StrVec {
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec& s) {
        std::pair<std::string*, std::string*> newData = alloc_n_copy(s.begin(), s.end());
        elements = newData.first;
        first_free = cap = newData.second;
    }
    StrVec& operator=(const StrVec& rhs) {
        std::pair<std::string*, std::string*> newData = alloc_n_copy(rhs.begin(), rhs.end());
        elements = newData.first;
        first_free = cap = newData.second;
        return *this;
    }
    ~StrVec() {
        free();
    }
    void push_back(const std::string& s) {
        chk_n_alloc();
        alloc.construct(first_free++, s);
    }
    template <typename... Args> void emplace_back(Args&&... args) {
        chk_n_alloc();
        alloc.construct(first_free++, std::forward<Args>(args)...);
    }

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string* b, const std::string* e) {
        std::string* newData = alloc.allocate(e - b);
        std::string* curr = newData;
        while(b != e) {
            alloc.construct(curr++, *b++);
        }
        return {newData, curr};
    }
    void free() {
        if (elements) {
            for (std::string* p = first_free; p != elements; ) {
                alloc.destroy(--p);
            }
            alloc.deallocate(elements, cap - elements);
        }
    }
    void reallocate() {
        size_t newCapacity = size() ? 2 * size() : 1;
        std::string* newData = alloc.allocate(newCapacity);
        std::string* dest = newData;
        std::string* elem = elements;
        for (size_t i = 0; i < size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();                         //一旦移动完元素就释放旧空间
        elements = newData;
        first_free = dest;
        cap = elements + newCapacity;
    }
    std::string* elements = nullptr;
    std::string* first_free = nullptr;
    std::string* cap = nullptr;
}