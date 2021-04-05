#include "Bulk_quote.h"
#include "Limit_quote.h"
#include "Quote.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print_debug(const Quote &q) { q.debug(); }

int main() {
  Quote q("aaa", 10.60);
  Bulk_quote bq("bbb", 111, 10, 0.3);
  Limit_quote lq("ccc", 222, 10, 0.3);

  //   q.debug();
  //   cout << endl;
  //   bq.debug();
  //   cout << endl;
  //   lq.debug();
  //   cout << endl;

  print_debug(q);
  cout << endl;
  print_debug(bq);
  cout << endl;
  print_debug(lq);
  cout << endl;

  return 0;
}