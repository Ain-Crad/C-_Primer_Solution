#include "Limit_quote.h"

double Limit_quote::net_price(size_t n) const {
  if (n <= quantity)
    return n * (1 - discount) * price;
  else
    return quantity * (1 - discount) * price + (n - quantity) * price;
}