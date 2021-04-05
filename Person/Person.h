#ifndef _Person_H
#define _Person_H

#include <iostream>
#include <string>

class Person;
std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

class Person
{
    friend std::istream &read(std::istream &is, Person &p);
    friend std::ostream &print(std::ostream &os, const Person &p);

public:
    Person() = default;
    Person(const std::string &n, const std::string &addr) : name(n), address(addr) {}
    Person(std::istream &is)
    {
        read(is, *this);
    }
    std::string getName() { return name; }
    std::string getAddress() { return address; }

private:
    std::string name;
    std::string address;
};

#endif