#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
bool compare(const T &v1, const T &v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

int main() {
  //   cout << compare<std::string>("a", "bbbb") << endl;
  //   cout << compare("a", "bb") << endl;
  return 0;
}