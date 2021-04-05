#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T, typename... Args>
void foo(const T &t, const Args &... rest) {
  cout << sizeof...(Args) << endl;
  cout << sizeof...(rest) << endl;
}

int main() {
  foo(1, 2.0, "hi", "hy");
  return 0;
}