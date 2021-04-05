#include "HasPtr.h"

using std::cin;
using std::cout;
using std::endl;

HasPtr &HasPtr::operator=(const HasPtr &hp)
{
    // cout << "HasPtr &operator=(const HasPtr &hp)" << endl;
    std::string *new_ps = new std::string(*hp.ps);
    delete ps;
    ps = new_ps;
    i = hp.i;

    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&hp) noexcept
{
    // cout << "HasPtr &operator=(HasPtr &&hp)" << endl;
    if (this != &hp)
    {
        delete ps;
        ps = hp.ps;
        i = hp.i;
        hp.ps = nullptr;
    }
    return *this;
}

// HasPtr &HasPtr::operator=(HasPtr rhs)
// {
//     swap(*this, rhs);
//     return *this;
// }

bool HasPtr::operator<(const HasPtr &hp)
{
    return *ps < *hp.ps;
}

HasPtr::HasPtr(HasPtr &&hp) noexcept
    : ps(hp.ps), i(hp.i)
{
    // cout << "HasPtr(HasPtr &&hp)" << endl;
    hp.ps = nullptr;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    // cout << "swap" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}