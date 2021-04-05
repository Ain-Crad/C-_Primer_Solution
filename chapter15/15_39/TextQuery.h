#ifndef _TEXT_QUERY_H
#define _TEXT_QUERY_H

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;

class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  using line_no = std::vector<std::string>::size_type;
  QueryResult(const std::string &s, std::shared_ptr<std::vector<std::string>> f,
              std::shared_ptr<std::set<line_no>> ls)
      : sought(s), file(f), lines(ls) {}
  std::set<line_no>::iterator begin() { return lines->begin(); }
  std::set<line_no>::iterator end() { return lines->end(); }
  std::shared_ptr<std::vector<std::string>> get_file() { return file; }

private:
  std::string sought;
  std::shared_ptr<std::vector<std::string>> file;
  std::shared_ptr<std::set<line_no>> lines;
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif