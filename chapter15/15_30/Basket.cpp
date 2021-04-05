#include "Basket.h"

using std::cin;
using std::cout;
using std::endl;

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << endl;
  return ret;
}

double Basket::total_receipt(std::ostream &os) const {
  double sum = 0.0;
  for (auto iter = items.cbegin(); iter != items.cend();
       iter = items.upper_bound(*iter)) {
    sum += print_total(os, **iter, items.count(*iter));
  }
  os << "Total Sale: " << sum << endl;
}