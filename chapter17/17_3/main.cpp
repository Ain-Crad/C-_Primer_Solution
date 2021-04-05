#include <fstream>
#include <iostream>

#include "TextQuery.h"

int main() {
  std::ifstream in("in.txt");
  TextQuery tq(in);
  print(std::cout, tq.query("hello")) << std::endl;
  print(std::cout, tq.query("you")) << std::endl;
  return 0;
}