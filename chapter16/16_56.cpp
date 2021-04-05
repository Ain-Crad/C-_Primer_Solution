#include <iostream>
#include <sstream>
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

template <typename T>
std::string debug_rep(const T &t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args &... rest) {
  return print(os, debug_rep(rest)...);
}

int main() {
  errorMsg(cout, 1, 2.0, "hi");
  return 0;
}