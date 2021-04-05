#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &);
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

void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "swap" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    HasPtr hp1("love");
    HasPtr hp2 = hp1;
    hp2 = hp1;
    hp2.setStr("breeze");
    cout << hp1.getStr() << " " << hp2.getStr() << endl;
    swap(hp1, hp2);
    cout << hp1.getStr() << " " << hp2.getStr() << endl;

    return 0;
}