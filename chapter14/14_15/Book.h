#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <string>

class Book
{
    friend std::istream &operator>>(std::istream &is, Book &);
    friend std::ostream &operator<<(std::ostream &os, const Book &);
    friend Book operator+(const Book &, const Book &);
    friend bool operator==(const Book &, const Book &);
    friend bool operator!=(const Book &, const Book &);

public:
    Book() = default;
    Book(const std::string &_name, std::string &_author, std::string &_publish_data, size_t _num)
        : name(_name), author(_author), publish_date(_publish_data), num(_num) {}
    Book(std::istream &is) { is >> *this; }

    Book &operator+=(const Book &);

private:
    std::string name;
    std::string author;
    std::string publish_date;
    size_t num = 0;
};

std::istream &operator>>(std::istream &is, Book &);
std::ostream &operator<<(std::ostream &os, const Book &);
Book operator+(const Book &, const Book &);
bool operator==(const Book &, const Book &);
bool operator!=(const Book &, const Book &);

#endif