#include "16.12.h"


template <typename T> bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
    return *lhs.data == *rhs.data;
}

template <typename T> BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}

template <typename T> BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, data->size());
}

template <typename T>
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)) { }

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::front() const{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::back() const{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subsript out of range");
    return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i) const{
    check(i, "subsript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}


/****************************class BlobPtr**************************/
//friend 
template <typename T> bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    return lhs.curr == rhs.curr;
}



template <typename T>
T& BlobPtr<T>::operator*() const{
    std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    check(curr, "decrement past begin of BlobPtr");
    --curr;
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}