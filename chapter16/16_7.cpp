#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T, size_t N> constexpr size_t getSize(const T (&)[N]) {
  return N;
}

int main() {
  int a[3] = {10, 1, 3};
  constexpr size_t n = getSize(a);
  cout << n << endl;
  char c[] = "s";
  cout << getSize(c) << endl;
  cout << strlen(c) << endl;
  return 0;
}