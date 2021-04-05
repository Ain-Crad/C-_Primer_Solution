#ifndef _BLOB_H
#define _BLOB_H

#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename T> class Blob {
  friend class BlobPtr<T>;
  friend bool operator==<T>(const Blob &lhs, const Blob &rhs);

public:
  typedef typename std::vector<T>::size_type size_type;
  Blob() : data(std::make_shared<std::vector<T>>()) {}
  Blob(std::initializer_list<T> il)
      : data(std::make_shared<std::vector<T>>(il)) {}
  Blob(const Blob &blob) : data(std::make_shared<std::vector<T>>(*blob.data)) {}
  Blob &operator=(const Blob &blob);

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  T &operator[](size_type i);
  T &front();
  T &back();

  const T &operator[](size_type i) const;
  const T &front() const;
  const T &back() const;

  void push_back(const T &t) { data->push_back(t); }
  void push_back(const T &&t) { data->push_back(std::move(t)); }
  void pop_back();

private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const;
};

template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
  return *lhs.data == *rhs.data;
}

template <typename T> Blob<T> &Blob<T>::operator=(const Blob &blob) {
  data = std::make_shared<std::vector<T>>(*blob.data);
  return *this;
}

template <typename T> T &Blob<T>::operator[](size_type i) {
  check(i, "out of range");
  return data->at(i);
}

template <typename T> const T &Blob<T>::operator[](size_type i) const {
  check(i, "out of range");
  return data->at(i);
}

template <typename T> T &Blob<T>::front() {
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T> const T &Blob<T>::front() const {
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T> T &Blob<T>::back() {
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T> const T &Blob<T>::back() const {
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T> void Blob<T>::pop_back() {
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

#endif