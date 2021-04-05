#include <iostream>
#include <string>

#include "Bulk_quote.h"
#include "Quote.h"

using std::cin;
using std::cout;
using std::endl;

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << endl;
  return ret;
}

int main() {
  Quote q("1001-X1", 1.5);
  Bulk_quote bq("1002-X2", 1.5, 2, 0.1);
  print_total(cout, q, 3);
  print_total(cout, bq, 3);
  return 0;
}