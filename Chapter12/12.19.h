#include <vector>
#include <memory>
#include <string>


class StrBlobPtr;
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    
    friend class StrBlobPtr;
    StrBlobPtr begin(); 
    StrBlobPtr end();

    
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


class StrBlobPtr{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz=0):wptr(a.data), curr(sz){}
    std::string& deref() const;
    StrBlobPtr& incr();
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};



