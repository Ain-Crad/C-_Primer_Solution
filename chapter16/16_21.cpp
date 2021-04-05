#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class DebugDelete {
public:
  DebugDelete(std::ostream &s = std::cerr) : os(s) {}
  template <typename T> void operator()(T *p) const {
    os << "deleting unique_ptr" << endl;
    delete p;
  }

private:
  std::ostream &os;
};

int main() {
  int *a = new int(10);
  DebugDelete d;
  d(a);
  return 0;
}