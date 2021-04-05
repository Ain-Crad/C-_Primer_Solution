#ifndef _DISC_QUOTE_H
#define _DISC_QUOTE_H

#include "Quote.h"
#include <iostream>
#include <string>

class Disc_quote : public Quote {
public:
  Disc_quote() { std::cout << "Disc_quote()" << std::endl; }
  Disc_quote(const std::string &book, double price, size_t qty, double disc)
      : Quote(book, price), quantity(qty), discount(disc) {
    std::cout << "Disc_quote(const std::string, double, size_t, double)"
              << std::endl;
  }
  Disc_quote(const Disc_quote &dq) : Quote(dq) {
    quantity = dq.quantity;
    discount = dq.discount;
    std::cout << "Disc_quote(const Disc_quote &)" << std::endl;
  }
  Disc_quote(const Disc_quote &&dq) : Quote(std::move(dq)) {
    quantity = std::move(dq.quantity);
    discount = std::move(dq.discount);
    std::cout << "Disc_quote(const Disc_quote &&)" << std::endl;
  }
  Disc_quote &operator=(const Disc_quote &rhs) {
    if (this != &rhs) {
      Quote::operator=(rhs);
      quantity = rhs.quantity;
      discount = rhs.discount;
    }
    std::cout << "Disc_quote &operator=(const Disc_quote &)" << std::endl;
    return *this;
  }
  Disc_quote &operator=(const Disc_quote &&rhs) {
    if (this != &rhs) {
      Quote::operator=(std::move(rhs));
      quantity = std::move(rhs.quantity);
      discount = std::move(rhs.discount);
    }
    std::cout << "Disc_quote &operator=(const Disc_quote &&)" << std::endl;
    return *this;
  }

  ~Disc_quote() override { std::cout << "~Disc_quote()" << std::endl; }

  double net_price(size_t) const = 0;

protected:
  size_t quantity = 0;
  double discount = 0.0;
};

#endif