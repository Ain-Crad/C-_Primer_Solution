#ifndef _BULK_QUOTE_H
#define _BULK_QUOTE_H

#include "Disc_quote.h"
#include <string>

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() { std::cout << "Bulk_quote()" << std::endl; }
  Bulk_quote(const std::string &book, double price, size_t qty, double disc)
      : Disc_quote(book, price, qty, disc) {
    std::cout << "Bulk_quote(const std::string &, double, size_t, double)"
              << std::endl;
  }
  Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {
    std::cout << "Bulk_quote(const Bulk_quote &)" << std::endl;
  }
  Bulk_quote(const Bulk_quote &&bq) : Disc_quote(std::move(bq)) {
    std::cout << "Bulk_quote(const Bulk_quote &&)" << std::endl;
  }
  Bulk_quote &operator=(const Bulk_quote &rhs) {
    if (this != &rhs) {
      Disc_quote::operator=(rhs);
    }
    std::cout << "Bulk_quote &operator=(const Bulk_quote &)" << std::endl;
    return *this;
  }
  Bulk_quote &operator=(const Bulk_quote &&rhs) {
    if (this != &rhs) {
      Disc_quote::operator=(std::move(rhs));
    }
    std::cout << "Bulk_quote &operator=(const Bulk_quote &&)" << std::endl;
    return *this;
  }

  ~Bulk_quote() override { std::cout << "~Bulk_quote()" << std::endl; }

  double net_price(size_t) const override;
};

#endif