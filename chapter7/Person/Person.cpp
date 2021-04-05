#include <iostream>
#include <string>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;

std::istream &read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.address;
    return os;
}

int main()
{
    freopen("person.txt", "r", stdin);

    Person p1(cin), p2(cin);
    // read(cin, p1);
    // read(cin, p2);
    print(cout, p1) << endl;
    print(cout, p2) << endl;
    return 0;
}