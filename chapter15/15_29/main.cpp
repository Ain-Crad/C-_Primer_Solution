#include <iostream>
#include <memory>
#include <vector>

#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Quote.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::vector<std::shared_ptr<Quote>> vec;
  vec.reserve(10);
  vec.push_back(std::make_shared<Quote>("Quote-book", 10.0));
  vec.push_back(std::make_shared<Bulk_quote>("Bulk-book", 10.0, 10, 0.5));
  for (auto &x : vec) {
    cout << x->net_price(10) << endl;
  }
  return 0;
}