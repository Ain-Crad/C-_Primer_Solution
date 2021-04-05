#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", std::regex::icase);
  cout << "Input a word, 'q' to quit:" << endl;
  std::string s;
  while (cin >> s && s != "q") {
    if (std::regex_match(s, r))
      cout << "Input word "
           << "\"" << s << "\""
           << " is okay." << endl;
    else
      cout << "Input word "
           << "\"" << s << "\""
           << " is not okay." << endl;
    cout << "Input a word, 'q' to quit:" << endl;
  }
  return 0;
}