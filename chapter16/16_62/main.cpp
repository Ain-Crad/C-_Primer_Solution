#include <iostream>
#include <unordered_set>

#include "Sales_data.h"

int main() {
  std::unordered_multiset<Sales_data> ums;
  Sales_data s1("xxx", 1, 2.0);
  Sales_data s2("xxx-xxx", 2, 1.5);
  ums.insert(s1);
  ums.insert(s2);
  for (auto &item : ums) {
    std::cout << item << std::endl;
  }
  return 0;
}