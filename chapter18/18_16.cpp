#include <iostream>

namespace Exercise {
int ivar = 0;
double dvar = 0;
const int limit = 1000;
}  // namespace Exercise

int ivar = 0;

// using Exercise::dvar;
// using Exercise::ivar;
// using Exercise::limit;

void manip() {
  //   using Exercise::dvar;
  //   using Exercise::ivar;
  //   using Exercise::limit;
  double dvar = 3.1416;
  int iobj = limit + 1;
  ++ivar;
  ++::ivar;
}

int main() {
  manip();
  return 0;
}