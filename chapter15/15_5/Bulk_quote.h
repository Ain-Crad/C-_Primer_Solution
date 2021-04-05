#ifndef _BULK_QUOTE_H
#define _BULK_QUOTE_H

#include "Quote.h"
#include <string>

class Bulk_quote : public Quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, size_t qty, double disc)
      : Quote(book, p), min_qty(qty), discount(disc) {}
  double net_price(std::size_t) const override;

private:
  size_t min_qty = 0;
  double discount = 0.0;
};

#endif