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

    HasPtr &operator=(const HasPtr &hp)
    {
        std::string *new_ps = new std::string(*hp.ps);
        delete ps;
        ps = new_ps;
        i = hp.i;
        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }

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
    HasPtr hp_c;
    hp_c = hp;
    hp_c.setString("hey");
    cout << hp.getString() << endl;
    cout << hp_c.getString() << endl;

    return 0;
}