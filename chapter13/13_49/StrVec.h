#ifndef _EXR_13_39_H
#define _EXR_13_39_H

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>


class StrVec {
public:
  StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string> ls);
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(StrVec &&) noexcept;
  ~StrVec();

  size_t size() const { return first_free - element; }
  size_t capacity() const { return cap - element; }
  void reserve(size_t n);
  void resize(size_t n);
  void resize(size_t n, const std::string &s);
  void push_back(const std::string &s);
  std::string *begin() const { return element; }
  std::string *end() const { return first_free; }
  std::string &at(size_t i) const;

private:
  static std::allocator<std::string> alloc;
  void chk_n_alloc();
  void reallocate();
  void free();
  std::pair<std::string *, std::string *> alloc_n_copy(std::string *,
                                                       std::string *);
  void alloc_n_move(size_t n);

  std::string *element;
  std::string *first_free;
  std::string *cap;
};

#endif