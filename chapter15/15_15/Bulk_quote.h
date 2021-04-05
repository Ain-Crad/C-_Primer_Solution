#ifndef _BULK_QUOTE_H
#define _BULK_QUOTE_H

#include "Disc_quote.h"
#include <string>

class Bulk_quote : public Disc_quote {
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, size_t qty, double disc)
      : Disc_quote(book, price, qty, disc) {}
  double net_price(size_t) const override;
};

#endif