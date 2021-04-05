#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <string>

class Book
{
    friend std::istream &operator>>(std::istream &is, Book &);
    friend std::ostream &operator<<(std::ostream &os, const Book &);

public:
    Book() = default;
    Book(size_t _num, const std::string &_name, std::string &_author, std::string &_publish_data)
        : num(_num), name(_name), author(_author), publish_date(_publish_data) {}
    Book(std::istream &is) { is >> *this; }

private:
    size_t num = 0;
    std::string name;
    std::string author;
    std::string publish_date;
};

std::istream &operator>>(std::istream &is, Book &);
std::ostream &operator<<(std::ostream &os, const Book &);

#endif