#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> vec = {"hello", "", "world", ""};
  std::function<bool(const string &)> fcn = &string::empty;
  int ret = std::count_if(vec.begin(), vec.end(), fcn);
  cout << ret << endl;
  return 0;
}