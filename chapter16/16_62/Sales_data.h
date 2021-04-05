#ifndef _SALES_DATA_H
#define _SALES_DATA_H

#include <functional>
#include <iostream>
#include <string>

class Sales_data {
  friend class std::hash<Sales_data>;
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend bool operator==(const Sales_data &, const Sales_data &);

 public:
  Sales_data() = default;
  Sales_data(const std::string &no) : bookNo(no) {}
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  Sales_data(std::istream &is);

  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

  Sales_data &operator+=(const Sales_data &);

 private:
  double avg_price() const;

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);
bool operator==(const Sales_data &, const Sales_data &);

inline double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

namespace std {
template <>
struct hash<Sales_data> {
  typedef size_t result_type;
  typedef Sales_data argument_type;
  size_t operator()(const Sales_data &) const;
};

inline size_t hash<Sales_data>::operator()(const Sales_data &s) const {
  return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^
         hash<double>()(s.revenue);
}

}  // namespace std

#endif