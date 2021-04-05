#include <iostream>

#include "Blob.h"
#include "BlobPtr.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Blob<int> blob1 = {1, 2, 3};
  Blob<int> blob2 = {1, 2, 3};
  cout << (blob1 == blob2) << endl;
  BlobPtr<int> ptr(blob1);
  cout << *ptr << endl;
  ++ptr;
  cout << *ptr << endl;
  return 0;
}