#ifndef _HASPTR_H
#define _HASPTR_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &);
    bool operator<(const HasPtr &);
    HasPtr(HasPtr &&) noexcept;
    HasPtr &operator=(HasPtr &&) noexcept;
    ~HasPtr() { delete ps; }

    // HasPtr &operator=(HasPtr);

    std::string getStr() { return *ps; }
    void setStr(const std::string &s) { *ps = s; }

private:
    std::string *ps;
    int i;
};

#endif