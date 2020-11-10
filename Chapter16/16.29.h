#include <vector>
#include <string>

#include "16.28.shared_ptr.h"

using std::string;
using std::vector;
using std::initializer_list;


template <typename> class Blob;
template <typename T> bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
    return *lhs.data == *rhs.data;
}

template <typename T>
class Blob{
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    
    Blob():data(new std::vector<T>()) { }
    template <typename It> Blob(It b, It e):data(new std::vector<T>(b,e)) { }
    Blob(initializer_list<T> il):data(new std::vector<T>(il)) { }

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加删除元素
    void push_back(const T &t){data->push_back(t);}
    //移动版本
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back() {
        check(0, "pop_back on empty Blob");
        data->pop_back();
    }
    //元素访问
    T &front() {
        check(0, "front on empty Blob");
        return data->front();
    }
    T &front() const{
        check(0, "front on empty Blob");
        return data->front();
    }
    T &back() {
        check(0, "back on empty Blob");
        return data->back();
    }
    T &back() const{
        check(0, "back on empty Blob");
        return data->back();
    }
    T &operator[](size_type i) {
        check(i, "subsript out of range");
        return (*data)[i];
    }
    T &operator[](size_type i) const{
        check(i, "subsript out of range");
        return (*data)[i];
    }
    
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const {
        if (i >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};





