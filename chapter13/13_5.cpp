#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}

    std::string getString() const
    {
        return *ps;
    }

    void setString(const std::string &s)
    {
        *ps = s;
    }

private:
    std::string *ps;
    int i;
};

int main()
{
    HasPtr hp("hello");
    HasPtr hp_c = hp;
    hp_c.setString("hi");
    cout << hp.getString() << endl;
    cout << hp_c.getString() << endl;

    return 0;
}