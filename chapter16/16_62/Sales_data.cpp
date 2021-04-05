#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

bool compareIsbn(const Sales_data &d1, const Sales_data &d2) {
  return d1.isbn() < d2.isbn();
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();

  return os;
}

std::istream &operator>>(std ::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  if (is) {
    item.revenue = item.units_sold * price;
  } else {
    item = Sales_data();
  }

  return is;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold &&
         lhs.revenue == rhs.revenue;
}