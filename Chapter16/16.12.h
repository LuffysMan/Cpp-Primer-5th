#include <vector>
#include <memory>
#include <string>

using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;
using std::initializer_list;

template <typename> class BlobPtr;
template <typename T> class Blob{
public:
    typedef vector<T>::size_type size_type;
    
    friend class BlobPtr<T>;
    BlobPtr begin(); 
    BlobPtr end();

    Blob():data(make_shared<vector<T>>()){}

    Blob(initializer_list<T> il):data(std::make_shared<vector<T>>(il)){}

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加删除元素
    void push_back(const T &t){data->push_back(t);}
    void pop_back();
    //元素访问
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    
private:
    shared_ptr<vector<T>> data;
    void check(size_t i, const T &msg) const;
};


template <typename T> class BlobPtr{
public:
    BlobPtr():curr(0){}
    BlobPtr(Blob &a, size_t sz=0):wptr(a.data), curr(sz){}
    T& deref() const;
    BlobPtr& incr();
    bool operator!=(const BlobPtr& p) { return p.curr != curr; }

private:
    shared_ptr<ector<T>> check(size_t, const T&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};



