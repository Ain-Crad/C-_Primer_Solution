//****************************************
// This program is still in error due to unknow factor
//****************************************

#include <fstream>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

int main() {
  fstream inOut("inOut", fstream::ate | fstream::in | fstream::out);
  if (!inOut) {
    std::cerr << "Unable to open file!" << endl;
    return -1;
  }

  auto end_mark = inOut.tellg();
  inOut.seekg(0, fstream::beg);
  string s;
  size_t cnt = 0;
  while (inOut && inOut.tellg() != end_mark && std::getline(inOut, s)) {
    cout << s << " " << inOut.tellg() << endl;
    cnt += s.size() + 1;
    auto mark = inOut.tellg();
    inOut.seekp(0, fstream::end);
    inOut << cnt;
    if (mark != end_mark) inOut << " ";
    inOut.seekg(mark);
  }
  inOut.seekp(0, fstream::end);
  inOut << "\n";
  inOut.close();

  return 0;
}