#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

template <typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T &val) {
  while (first != last) {
    if (*first == val) {
      return first;
    }
    ++first;
  }
  return last;
}

int main() {
  std::vector<int> vec = {1, 2, 3};
  auto it = std::find(vec.begin(), vec.end(), 3);
  if (it != vec.end()) {
    cout << "Element found: " << *it << endl;
  } else {
    cout << "Element not found" << endl;
  }
  std::list<std::string> lst = {"hi", "hello", "world"};
  auto it2 = std::find(lst.begin(), lst.end(), "hey");
  if (it2 != lst.end()) {
    cout << "Element found: " << *it2 << endl;
  } else {
    cout << "Element not found" << endl;
  }
  return 0;
}