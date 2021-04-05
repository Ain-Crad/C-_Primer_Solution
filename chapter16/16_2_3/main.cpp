#include <iostream>
#include <typeinfo>

#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

template <typename T> int compare(const T &v1, const T &v2) {
  if (v1 < v2)
    return -1;
  if (v2 < v1)
    return 1;
  return 0;
}

int main() {
  cout << compare(1, 0) << endl;
  //   Sales_data s1("book1");
  //   Sales_data s2("book2");
  //   cout << compare(s1, s2) << endl;
  return 0;
}