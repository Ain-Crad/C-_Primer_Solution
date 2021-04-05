#ifndef _StrBlob_H
#define _StrBlob_H

#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;

class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  friend bool operator<(const StrBlob &, const StrBlob &);
  friend bool operator>(const StrBlob &, const StrBlob &);

public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob() : data(std::make_shared<std::vector<std::string>>()){};
  StrBlob(std::initializer_list<std::string> il)
      : data(std::make_shared<std::vector<std::string>>(il)){};
  StrBlob(const StrBlob &blob)
      : data(std::make_shared<std::vector<std::string>>(*blob.data)) {}
  StrBlob &operator=(const StrBlob &blob);
  std::string &operator[](size_t n);
  const std::string &operator[](size_t n) const;

  std::string &front();
  std::string &back();
  const std::string &front() const;
  const std::string &back() const;
  void push_back(const std::string &s);
  void push_back(std::string &&s);
  void pop_back();

  StrBlobPtr begin();
  StrBlobPtr end();

private:
  std::shared_ptr<std::vector<std::string>> data;

  void check(size_type i, const std::string &msg) const;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  std::string &deref() const;
  StrBlobPtr &incr();
  bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
  std::string &operator[](size_t n);
  const std::string &operator[](size_t n) const;
  StrBlobPtr &operator++();
  StrBlobPtr &operator--();
  StrBlobPtr operator++(int);
  StrBlobPtr operator--(int);
  StrBlobPtr operator+(size_t) const;
  StrBlobPtr operator-(size_t) const;
  std::string &operator*() const;
  std::string *operator->() const;

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

#endif