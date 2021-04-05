#ifndef _QUOTE_H
#define _QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double sales_prices)
      : bookNo(book), price(sales_prices) {}
  virtual ~Quote() = default;

  std::string isbn() const { return bookNo; }
  virtual double net_price(size_t n) const { return n * price; }
  virtual void debug() const;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

#endif