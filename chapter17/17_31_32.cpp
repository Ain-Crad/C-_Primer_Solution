#include <iostream>
#include <random>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string resp;
  std::default_random_engine e;
  std::bernoulli_distribution b;
  do {
    bool first = b(e);
    cout << (first ? "We go first" : " You get to go first") << endl;
    cout << "play again? Enter 'yes' or 'no'" << endl;
  } while (cin >> resp && resp[0] == 'y');
  return 0;
}
