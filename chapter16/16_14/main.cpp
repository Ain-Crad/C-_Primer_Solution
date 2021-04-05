#include <iostream>

#include "Screen.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Screen<5, 5> sc('c');
  cout << sc << endl;
  cin >> sc;
  cout << sc << endl;
  return 0;
}