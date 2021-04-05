#include <iostream>
#include <string>

#include "SharedPointer.h"
#include "UniquePointer.h"

int main() {
  auto sp = SharedPointer<int>(new int(42));
  auto sp2(sp);
  std::cout << *sp << std::endl;
  std::cout << sp.use_count() << std::endl;

  auto string_ptr = SharedPointer<std::string>{new std::string{"Yue"}};
  std::cout << *string_ptr << std::endl;
  std::cout << string_ptr->size() << std::endl;

  UniquePointer<int> up(new int(100));
  std::cout << *up << std::endl;

  return 0;
}