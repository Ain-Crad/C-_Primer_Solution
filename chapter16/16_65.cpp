#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
std::string debug_rep(const T &t);

template <typename T>
std::string debug_rep(T *p);

template <>
std::string debug_rep(const char *str);

template <>
std::string debug_rep(char *str);

template <typename T>
std::string debug_rep(const T &t) {
  cout << "debug_rep(const T &t)" << endl;
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T>
std::string debug_rep(T *p) {
  cout << "debug_rep(T *p)" << endl;
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}

template <>
std::string debug_rep(const char *str) {
  cout << "debug_rep(const char *str)" << endl;
  std::ostringstream ret;
  ret << str;
  return ret.str();
}

template <>
std::string debug_rep(char *str) {
  cout << "debug_rep(char *str)" << endl;
  std::ostringstream ret;
  ret << str;
  return ret.str();
}

int main() {
  char p[] = "alan";
  const char *p2 = "hello";
  std::cout << debug_rep(p) << endl;
  std::cout << debug_rep(p2) << endl;
  return 0;
}