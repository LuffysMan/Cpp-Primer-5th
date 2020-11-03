#include "./12.22.h"


void StrBlob::check(size_t i, const std::string &msg) const{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::back() const{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}


std::shared_ptr<std::vector<std::string>> 
ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const{
    std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
    if (!ret){
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()){
        throw std::out_of_range(msg);
    }
    return ret;
}

const std::string& ConstStrBlobPtr::deref() const{
    std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
    return (*p)[curr];
}

const std::string& ConstStrBlobPtr::deref(size_t pos) const{
    std::shared_ptr<std::vector<std::string>> p = check(pos, "dereference past end");
    return (*p)[pos];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr(){
    //如果curr已经指向容器的尾后位置, 就不能递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


ConstStrBlobPtr StrBlob::begin() const // should add const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const // should add const
{
    return ConstStrBlobPtr(*this, data->size());
}