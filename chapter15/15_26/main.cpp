#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Quote.h"
#include <iostream>
#include <string>

int main() {
  //   Quote q;
  Bulk_quote bq;
  Bulk_quote bq2(bq);
  return 0;
}