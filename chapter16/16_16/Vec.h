#ifndef _VEC_H
#define _VEC_H

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

template <typename T> class Vec {
public:
  Vec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
  Vec(std::initializer_list<T> il);
  Vec(const Vec &);
  Vec &operator=(const Vec &);
  Vec(Vec &&) noexcept;
  Vec &operator=(Vec &&) noexcept;
  ~Vec();

  size_t size() const { return first_free - element; }
  size_t capacity() const { return cap - element; }
  void reserve(size_t n);
  void resize(size_t n);
  void resize(size_t n, const T &);
  void push_back(const T &);
  void pop_back();
  T *begin() { return element; }
  const T *begin() const { return element; }
  T *end() { return first_free; }
  const T *end() const { return first_free; }
  T &at(size_t i);
  const T &at(size_t i) const;
  T &operator[](size_t n);
  const T &operator[](size_t n) const;

private:
  static std::allocator<T> alloc;
  void free();
  void alloc_n_move(size_t n);
  T *element;
  T *first_free;
  T *cap;
};

template <typename T> std::allocator<T> Vec<T>::alloc;

template <typename T> Vec<T>::Vec(std::initializer_list<T> il) {
  auto data = alloc.allocate(il.size());
  auto dest = data;
  for (auto it = il.begin(); it != il.end(); ++it) {
    alloc.construct(dest++, *it);
  }
  element = data;
  first_free = cap = dest;
}

template <typename T> Vec<T>::Vec(const Vec &v) {
  auto data = alloc.allocate(v.first_free - v.element);
  auto dest = data;
  for (auto it = v.begin(); it != v.end(); ++it) {
    alloc.construct(dest++, *it);
  }
  element = data;
  first_free = cap = dest;
}

template <typename T> Vec<T> &Vec<T>::operator=(const Vec &v) {
  if (&v != this) {
    free();
    auto data = alloc.allocate(v.first_free - v.element);
    auto dest = data;
    for (auto it = v.begin(); it != v.end(); ++it) {
      alloc.construct(dest++, *it);
    }
    element = data;
    first_free = cap = dest;
  }
  return *this;
}

template <typename T>
Vec<T>::Vec(Vec &&v) noexcept
    : element(v.element), first_free(v.first_free), cap(v.cap) {
  v.element = v.first_free = v.cap = nullptr;
}

template <typename T> Vec<T> &Vec<T>::operator=(Vec &&v) noexcept {
  if (&v != this) {
    free();
    element = v.element;
    first_free = v.first_free;
    cap = v.cap;
    v.element = v.first_free = v.cap = nullptr;
  }
  return *this;
}

template <typename T> Vec<T>::~Vec() { free(); }

template <typename T> void Vec<T>::free() {
  if (element) {
    std::for_each(element, first_free, [](const T &t) { alloc.destroy(&t); });
    alloc.deallocate(element, cap - element);
  }
}

template <typename T> void Vec<T>::alloc_n_move(size_t n) {
  auto newData = alloc.allocate(n);
  auto dest = newData;
  for (auto p = element; p != first_free; ++p) {
    alloc.construct(dest++, std::move(*p));
  }
  free();
  element = newData;
  first_free = dest;
  cap = element + n;
}

template <typename T> void Vec<T>::reserve(size_t n) {
  if (n < capacity()) {
    return;
  }
  alloc_n_move(n);
}

template <typename T> void Vec<T>::resize(size_t n) { resize(n, T()); }

template <typename T> void Vec<T>::resize(size_t n, const T &t) {
  if (n < size()) {
    while (first_free != element + n) {
      alloc.destroy(--first_free);
    }
  } else {
    if (n > capacity()) {
      reserve(2 * n);
    }
    for (size_t i = size(); i < n; ++i) {
      alloc.construct(first_free++, t);
    }
  }
}

template <typename T> void Vec<T>::push_back(const T &t) {
  if (size() == capacity()) {
    size_t newCapacity = size() ? 2 * size() : 1;
    alloc_n_move(newCapacity);
  }
  alloc.construct(first_free++, t);
}

template <typename T> void Vec<T>::pop_back() {
  if (!size()) {
    throw std::runtime_error("Vec is empty");
  }
  alloc.destory(--first_free);
}

template <typename T> T &Vec<T>::at(size_t i) {
  if (i >= size()) {
    throw std::out_of_range("Vec indice out of range");
  }
  return *(element + i);
}

template <typename T> const T &Vec<T>::at(size_t i) const {
  if (i >= size()) {
    throw std::out_of_range("Vec indice out of range");
  }
  return *(element + i);
}

template <typename T> T &Vec<T>::operator[](size_t i) { return *(element + i); }

template <typename T> const T &Vec<T>::operator[](size_t i) const {
  return *(element + i);
}

#endif