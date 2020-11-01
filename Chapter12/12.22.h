#include <vector>
#include <memory>
#include <string>


class ConstStrBlobPtr;
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    
    friend class ConstStrBlobPtr;
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;
    
    StrBlob():data(std::make_shared<std::vector<std::string>>()){}

    StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加删除元素
    void push_back(const std::string &t){data->push_back(t);}
    void pop_back();
    //元素访问
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;
    
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_t i, const std::string &msg) const;
};


class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {} // should add const
    bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
    const std::string& deref() const
    { // return value should add const
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};



