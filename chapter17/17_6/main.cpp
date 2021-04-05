#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std::vector;

struct matches {
  matches(vector<Sales_data>::size_type _id,
          vector<Sales_data>::const_iterator _first_it,
          vector<Sales_data>::const_iterator _last_it)
      : id(_id), first_it(_first_it), last_it(_last_it) {}

  vector<Sales_data>::size_type id;
  vector<Sales_data>::const_iterator first_it;
  vector<Sales_data>::const_iterator last_it;
};

vector<matches> findBook(const vector<vector<Sales_data>> &files,
                         const string &book) {
  vector<matches> ret;
  for (auto it = files.cbegin(); it != files.cend(); ++it) {
    auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second) {
      ret.push_back(matches(it - files.cbegin(), found.first, found.second));
    }
  }
  return ret;
}

void reportResults(std::istream &in, std::ostream &os,
                   const vector<vector<Sales_data>> &files) {
  string s;
  while (in >> s) {
    if (s == "q") break;
    auto trans = findBook(files, s);
    if (trans.empty()) {
      cout << s << " not found in any stores" << endl;
      continue;
    }
    for (const auto &store : trans) {
      os << "store " << store.id << " sales: "
         << std::accumulate(store.first_it, store.last_it, Sales_data(s))
         << endl;
    }
  }
}

int main() {
  vector<vector<Sales_data>> files{
      {Sales_data("xxx-1", 1, 1.0), Sales_data("xxx-1", 1, 1.5),
       Sales_data("xxx-2", 2, 2.0)},
      {Sales_data("xxx-1", 2, 4.0)}};
  reportResults(cin, cout, files);
  return 0;
}