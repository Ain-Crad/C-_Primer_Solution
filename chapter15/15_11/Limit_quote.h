#ifndef _LIMIT_QUOTE_H
#define _LIMIT_QUOTE_H

#include "Quote.h"
#include <string>

class Limit_quote : public Quote {
public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double p, size_t qty, double disc)
      : Quote(book, p), max_qty(qty), discount(disc) {}
  double net_price(size_t) const override;

private:
  size_t max_qty = 0;
  double discount = 0.0;
};

#endif