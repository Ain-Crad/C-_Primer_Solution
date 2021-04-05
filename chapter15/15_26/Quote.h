#ifndef _QUOTE_H
#define _QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
  Quote() { std::cout << "Quote()" << std::endl; }
  Quote(const std::string &book, double sales_prices)
      : bookNo(book), price(sales_prices) {
    std::cout << "Quote(const std::string , double)" << std::endl;
  }
  Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
    std::cout << "Quote(const Quote &)" << std::endl;
  }
  Quote(const Quote &&q) noexcept
      : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
    std::cout << "Quote(const Quote &&)" << std::endl;
  }
  Quote &operator=(const Quote &rhs) {
    if (this != &rhs) {
      bookNo = rhs.bookNo;
      price = rhs.price;
    }
    std::cout << "Quote &operator=(const Quote &)" << std::endl;
    return *this;
  }
  Quote &operator=(const Quote &&rhs) noexcept {
    if (this != &rhs) {
      bookNo = std::move(rhs.bookNo);
      price = std::move(rhs.price);
    }
    std::cout << "Quote &operator=(const Quote &&)" << std::endl;
    return *this;
  }
  virtual ~Quote() { std::cout << "~Quote()" << std::endl; }

  std::string isbn() const { return bookNo; }
  virtual double net_price(size_t n) const { return n * price; }
  virtual void debug() const;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

#endif