#ifndef _QUERY_BASE_H
#define _QUERY_BASE_H

#include "TextQuery.h"
#include <string>

class Query_base {
protected:
  using line_no = TextQuery::line_no;
  virtual ~Query_base() {}

private:
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual std::string rep() const = 0;
};

#endif