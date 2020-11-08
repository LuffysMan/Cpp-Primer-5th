#include <vector>
#include <memory>
#include <string>

using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;
using std::initializer_list;


template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    
    Blob();
    template <typename It> Blob(It b, It e);
    Blob(initializer_list<T> il);

    BlobPtr<T> begin();
    BlobPtr<T> end();

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加删除元素
    void push_back(const T &t){data->push_back(t);}
    //移动版本
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    //元素访问
    T &front();
    T &front() const;
    T &back();
    T &back() const;
    T &operator[] (size_type i);
    T &operator[] (size_type i) const;
    
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const;
};


template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
class BlobPtr{
public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T> &a, size_t sz = 0):wptr(a.data), curr(sz){}
    T& operator*() const;
    //前置运算符
    BlobPtr& operator++();
    BlobPtr& operator--();
    //后置运算符
    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    shared_ptr<vector<T>> check(size_t, const T&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};



