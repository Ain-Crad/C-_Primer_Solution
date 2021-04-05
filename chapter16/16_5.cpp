#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T, size_t N> void print(const T (&arr)[N]) {
  for (auto elem : arr) {
    cout << elem << " ";
  }
  cout << endl;
}

// template <typename Arr> void print(const Arr &arr) {
//   for (auto elem : arr) {
//     cout << elem << " ";
//   }
//   cout << endl;
// }

int main() {
  int a[3] = {1, 2, 3};
  print(a);
  char c[4] = {'a', 'b', 'c', 'd'};
  print(c);
  return 0;
}