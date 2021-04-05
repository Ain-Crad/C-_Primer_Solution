#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::sregex_iterator;
using std::string;

int main() {
  string s;
  cout << "Please input a sequence of words:" << endl;
  getline(cin, s);
  cout << endl;
  cout << "Word(s) that violiate the \"ei\" grammar rule:" << endl;
  string pattern("[^c]ei");
  pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
  regex r(pattern, regex::icase);

  for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
    cout << it->str() << endl;
  }
  return 0;
}