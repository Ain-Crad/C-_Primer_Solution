#include "Book.h"

std::istream &operator>>(std::istream &is, Book &bk)
{
    is >> bk.name >> bk.author >> bk.publish_date >> bk.num;
    if (!is)
    {
        bk = Book();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Book &bk)
{
    os << bk.name << " " << bk.author
       << " " << bk.publish_date << " " << bk.num;
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
    if (lhs.name == rhs.name && lhs.author == lhs.author && lhs.publish_date == rhs.publish_date)
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
    if (lhs.name != rhs.name || lhs.author != rhs.author || lhs.publish_date != rhs.publish_date)
    {
        return false;
    }
    else
    {
        return true;
    }
}