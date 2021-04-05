#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { cout << "HasPtr(const HasPtr &hp)" << endl; }
    HasPtr &operator=(const HasPtr &);
    bool operator<(const HasPtr &);
    ~HasPtr() { delete ps; }

    std::string getStr() { return *ps; }
    void setStr(const std::string &s) { *ps = s; }

private:
    std::string *ps;
    int i;
};

HasPtr &HasPtr::operator=(const HasPtr &hp)
{
    std::string *new_ps = new std::string(*hp.ps);
    delete ps;
    ps = new_ps;
    i = hp.i;

    return *this;
}

bool HasPtr::operator<(const HasPtr &hp)
{
    return *ps < *hp.ps;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "swap" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    std::vector<HasPtr> vec;
    vec.reserve(10);
    vec.push_back(HasPtr("hi"));
    vec.push_back(HasPtr("hello"));
    vec.push_back(HasPtr("hey"));

    std::sort(vec.begin(), vec.end());

    for (auto &x : vec)
    {
        cout << x.getStr() << endl;
    }

    return 0;
}