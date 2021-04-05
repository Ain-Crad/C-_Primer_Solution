#ifndef _TEXT_QUERY_H
#define _TEXT_QUERY_H

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

class TextQuery {
 public:
  using line_no = std::vector<std::string>::size_type;
  using result_tuple =
      std::tuple<std::string, std::shared_ptr<std::vector<std::string>>,
                 std::shared_ptr<std::set<line_no>>>;

  TextQuery(std::ifstream &);
  result_tuple query(const std::string &) const;

 private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

std::ostream &print(std::ostream &os, const TextQuery::result_tuple &rt);

#endif