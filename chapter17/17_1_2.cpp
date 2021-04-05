#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main() {
  std::tuple<int, int, int> t(10, 20, 30);
  std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>>
      t2("hi", {"hello", "world"}, {"haha", 3});
  return 0;
}