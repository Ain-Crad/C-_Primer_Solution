#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
std::ostream &print(std::ostream &os, const T &t) {
  return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &... rest) {
  os << t << ", ";
  return print(os, rest...);
}

int main() {
  print(cout, 1) << endl;
  print(cout, 1, 2.0) << endl;
  print(cout, 1, 2.0, 'c', "hi", std::string("hello"));
  return 0;
}