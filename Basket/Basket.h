#ifndef _BASKET_H
#define _BASKET_H

// #include "Bulk_quote.h"
// #include "Disc_quote.h"
#include "Quote.h"
#include <iostream>
#include <memory>
#include <set>

class Basket {
public:
  void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
  void add_item(const Quote &sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
  }
  void add_item(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }
  double total_receipt(std::ostream &) const;

private:
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double print_total(std::ostream &os, const Quote &item, size_t n);

#endif