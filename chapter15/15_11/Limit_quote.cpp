#include "Limit_quote.h"

double Limit_quote::net_price(size_t cnt) const {
  if (cnt <= max_qty)
    return cnt * (1 - discount) * price;
  else
    return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
}