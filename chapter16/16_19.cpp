#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// template <typename T> void print(const std::vector<T> &vec) {
//   typedef typename std::vector<T>::size_type size_type;
//   for (size_type i = 0; i < vec.size(); ++i) {
//     cout << vec.at(i) << " ";
//   }
//   cout << endl;
// }

template <typename Container> void print(const Container &c) {
  typedef typename Container::size_type size_type;
  for (size_type i = 0; i < c.size(); ++i) {
    cout << c.at(i) << " ";
  }
  cout << endl;
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  print(vec);
  return 0;
}