#include "StrBlob.h"

StrBlob &StrBlob::operator=(const StrBlob &blob)
{
    data = std::make_shared<std::vector<std::string>>(*blob.data);
    return *this;
}

std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::push_back(const std::string &s)
{
    data->push_back(s);
}

void StrBlob::push_back(std::string &&s)
{
    data->push_back(std::move(s));
}

void StrBlob::pop_back()
{
    data->pop_back();
}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data != *rhs.data;
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data > *rhs.data;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    if (*lhs.wptr.lock() == *rhs.wptr.lock() && lhs.curr == rhs.curr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

std::string &StrBlob::operator[](size_t n)
{
    check(n, "out of range");
    return data->at(n);
}
const std::string &StrBlob::operator[](size_t n) const
{
    check(n, "out of range");
    return data->at(n);
}

std::string &StrBlobPtr::operator[](size_t n)
{
    auto p = check(n, "out of range");
    return (*p)[n];
}
const std::string &StrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "out of range");
    return (*p)[n];
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}
StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(size_t) const
{
    StrBlobPtr ret = *this;
    ret.curr += n;
    check(ret.curr, "increment past end of StrBlobPtr");
    return ret;
}
StrBlobPtr StrBlobPtr::operator-(size_t) const
{
    StrBlobPtr ret = *this;
    ret.curr -= n;
    check(ret.curr, "decrement pass end of StrBlobPtr");
    return ret;
}

std::string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
std::string *StrBlobPtr::operator->() const
{
    return &this->operator*();
}