#include <iostream>
#include <string>

#include "Blob.h"
#include "BlobPtr.h"

int main() {
  Blob<std::string> b1 = {"hello", "world"};
  Blob<std::string> b2 = {"hi", "there"};
  BlobPtr<std::string> p1(b1);
  BlobPtr<std::string> p2(b2);
  std::cout << *p1 << std::endl;
  std::cout << *p2 << std::endl;
  std::cout << (p1 == p2) << std::endl;
  return 0;
}