#include <iostream>
#include <string>

#include "Quote.h"

using std::cin;
using std::cout;
using std::endl;

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

double Limit_quote::net_price(size_t cnt) const {
  if (cnt <= max_qty)
    return cnt * (1 - discount) * price;
  else
    return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
}

int main() { return 0; }