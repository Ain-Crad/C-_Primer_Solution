#include "Basket.h"
#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Quote.h"
#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

int main() {
  Basket bsk;
  Quote q("Quote-book", 10.0);
  Bulk_quote bq("Bulk_quote-book", 10.0, 10, 0.5);
  bsk.add_item(q);
  for (int i = 0; i < 10; ++i) {
    bsk.add_item(bq);
  }
  bsk.total_receipt(cout);
  return 0;
}