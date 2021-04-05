#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::tuple;
using std::vector;

typedef pair<vector<Sales_data>::size_type,
             pair<vector<Sales_data>::const_iterator,
                  vector<Sales_data>::const_iterator>>
    matches;

vector<matches> findBook(const vector<vector<Sales_data>> &files,
                         const string &book) {
  vector<matches> ret;
  for (auto it = files.cbegin(); it != files.cend(); ++it) {
    auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second) {
      ret.push_back(std::make_pair(it - files.cbegin(),
                                   make_pair(found.first, found.second)));
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
      os << "store " << store.first << " sales: "
         << std::accumulate(store.second.first, store.second.second,
                            Sales_data(s))
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