#include "StrVec.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  StrVec sv = {"hello", "world"};
  cout << *sv.begin() << endl;
  const StrVec sv2 = {"world"};
  cout << *sv2.begin() << endl;
  return 0;
}