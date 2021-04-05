#ifndef _EXR_13_26_H
#define _EXR_13_26_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() : data(std::make_shared<std::vector<std::string>>()){};
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)){};
    StrBlob(const StrBlob &blob) : data(std::make_shared<std::vector<string>>(*blob.data)) {}
    StrBlob &operator=(const StrBlob &blob);

    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;
    void push_back(const std::string &s);
    void pop_back();

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string &deref() const;
    StrBlobPtr &incr();
    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif