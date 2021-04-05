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