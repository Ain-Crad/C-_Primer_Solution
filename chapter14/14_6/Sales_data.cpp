#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

bool compareIsbn(const Sales_data &d1, const Sales_data &d2)
{
    return d1.isbn() < d2.isbn();
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}
