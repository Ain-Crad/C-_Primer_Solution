#include "Book.h"

std::istream &operator>>(std::istream &is, Book &bk)
{
    is >> bk.num >> bk.name >> bk.author >> bk.publish_date;
    if (!is)
    {
        bk = Book();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Book &bk)
{
    os << bk.num << " " << bk.name << " "
       << bk.author << " " << bk.publish_date;
    return os;
}

Book &Book::operator+=(const Book &rhs)
{
    if (*this == rhs)
    {
        this->num += rhs.num;
    }

    return *this;
}

Book operator+(const Book &lhs, const Book &rhs)
{
    Book book = lhs;
    book += rhs;
    return book;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    if (lhs.name == rhs.name && lhs.author == lhs.author)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator!=(const Book &lhs, const Book &rhs)
{
    if (lhs.name != rhs.name || lhs.author != rhs.author)
    {
        return false;
    }
    else
    {
        return true;
    }
}