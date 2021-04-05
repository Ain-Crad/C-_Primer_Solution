#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T, size_t N> T *begin(T (&arr)[N]) { return arr; }
template <typename T, size_t N> T *end(T (&arr)[N]) { return arr + N; }
int main() {
  int a[3] = {10, 2, 3};
  for (auto it = begin(a); it != end(a); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}