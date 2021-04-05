#include "TextQuery.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
  string text;
  line_no lineNum = 0;
  while (getline(is, text)) {
    file->push_back(text);
    istringstream line(text);
    string word;
    while (line >> word) {
      auto &lines = wm[word];
      if (!lines) {
        lines.reset(new set<line_no>);
      }
      lines->insert(lineNum);
    }
    ++lineNum;
  }
}

TextQuery::result_tuple TextQuery::query(const string &sought) const {
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  auto found = wm.find(sought);
  if (found == wm.end())
    return result_tuple(sought, file, nodata);
  else
    return result_tuple(sought, file, found->second);
}

string make_plural(size_t ctr, const string &word, const string &ending) {
  if (ctr > 1)
    return word + ending;
  else
    return word;
}

ostream &print(ostream &os, const TextQuery::result_tuple &rt) {
  os << std::get<0>(rt) << " occurs " << std::get<2>(rt)->size() << " "
     << make_plural(std::get<2>(rt)->size(), "time", "s") << endl;
  for (auto num : *(std::get<2>(rt))) {
    os << "\t(line " << num + 1 << ") ";
    os << std::get<1>(rt)->at(num) << endl;
  }
  return os;
}