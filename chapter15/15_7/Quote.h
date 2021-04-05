#ifndef _QUOTE_H
#define _QUOTE_H

#include <string>

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double sales_prices)
      : bookNO(book), price(sales_prices) {}
  virtual ~Quote() = default;

  std::string isbn() const { return bookNO; }
  virtual double net_price(size_t n) const { return n * price; }

private:
  std::string bookNO;

protected:
  double price = 0.0;
};


#endif