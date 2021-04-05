#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
size_t find_occurrence(std::vector<T> &vec, T t) {
  size_t cnt = 0;
  for (const auto &x : vec) {
    if (x == t) ++cnt;
  }
  return cnt;
}

template <>
size_t find_occurrence(std::vector<const char *> &vec, const char *t) {
  size_t cnt = 0;
  for (const auto &x : vec) {
    if (strcmp(x, t) == 0) ++cnt;
  }
  return cnt;
}

int main() {
  std::vector<double> vd = {1.1, 1.1, 2.3, 4};
  std::cout << find_occurrence(vd, 1.1) << std::endl;
  std::vector<std::string> vs = {"hello", "world"};
  std::cout << find_occurrence(vs, std::string("hello"));
  std::vector<const char *> vcc = {"alan", "alan", "alan", "alan", "moophy"};
  std::cout << find_occurrence(vcc, "alan") << std::endl;

  return 0;
}