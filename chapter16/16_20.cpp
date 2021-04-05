#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// template <typename T> void print(const std::vector<T> &vec) {
//   typedef typename std::vector<T>::size_type size_type;
//   for (auto it = vec.begin(); it != vec.end(); ++it) {
//     cout << *it << " ";
//   }
//   cout << endl;
// }

template <typename Container> void print(const Container &c) {
  typedef typename Container::size_type size_type;
  for (auto it = c.begin(); it != c.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  std::vector<int> vec = {1, 2, 3};
  print(vec);
  return 0;
}