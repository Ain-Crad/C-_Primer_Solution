#include "Vec.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  Vec<int> vec = {1, 2, 3, 4, 5};
  Vec<int> v2;

  v2 = vec;
  std::cout << v2.capacity() << std::endl;
  v2.push_back(99);
  v2.resize(8, 2);
  for (size_t i = 0; i < v2.size(); ++i) {
    cout << v2.at(i) << " ";
  }
  cout << endl;
  for (size_t i = 0; i < v2.size(); ++i) {
    cout << v2[i] << " ";
  }
  cout << endl;
  return 0;
}