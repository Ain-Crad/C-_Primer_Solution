#ifndef _UNIQUE_POINTER_H
#define _UNIQUE_POINTER_H

#include <iostream>

class DebugDelete {
public:
  DebugDelete(std::ostream &s = std::cerr) : os(s) {}
  template <typename T> void operator()(T *p) const {
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};

template <typename T, typename D = DebugDelete> class UniquePointer {
public:
  UniquePointer() = default;
  explicit UniquePointer(T *p) : ptr(p) {}
  UniquePointer(const UniquePointer &) = delete;
  UniquePointer &operator=(const UniquePointer &) = delete;
  ~UniquePointer() { deleter(ptr); }

  T &operator*() const { return *ptr; }
  T *operator->() const { return ptr; }
  operator bool() const { return ptr ? true : false; }

  T *get() const { return ptr; }
  void reset() {
    deleter(ptr);
    ptr = nullptr;
  }
  void reset(T *p) {
    deleter(ptr);
    ptr = p;
  }
  T *release() {
    T *ret = ptr;
    ptr = nullptr;
    return ret;
  }

private:
  T *ptr = nullptr;
  D deleter = D();
};

#endif