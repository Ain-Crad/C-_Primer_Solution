#include <bitset>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::vector<int> vec{1, 2, 3, 5, 8, 13, 21};
  std::bitset<32> bset;
  for (auto i : vec) bset.set(i);

  std::bitset<32> bset2;
  for (unsigned i = 0; i != 32; ++i) {
    bset2[i] = bset[i];
  }
  cout << bset << endl;
  cout << bset2 << endl;
  return 0;
}