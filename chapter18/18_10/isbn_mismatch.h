#ifndef _ISBN_MISMATCH_H
#define _ISBN_MISMATCH_H

#include <stdexcept>
#include <string>

class isbn_mismatch : public std::logic_error {
 public:
  explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
  isbn_mismatch(const std::string &s, const std::string &lhs,
                const std::string &rhs)
      : std::logic_error(s), left(lhs), right(rhs) {}
  const std::string left, right;
};

#endif