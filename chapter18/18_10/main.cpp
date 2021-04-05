#include <exception>
#include <iostream>
#include <stdexcept>

#include "Sales_data.h"

int main() {
  Sales_data item1, item2, sum;
  while (std::cin >> item1 >> item2) {
    try {
      sum = item1 + item2;
    } catch (const isbn_mismatch &e) {
      std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn("
                << e.right << ")" << std::endl;
    }
  }
  return 0;
}