#ifndef _SHARED_POINTER_H
#define _SHARED_POINTER_H

#include <functional>

template <typename T>
void Delete(T *p) {
  delete p;
}

template <typename T>
class SharedPointer {
 public:
  SharedPointer() : ptr(nullptr), ref_count(new size_t(1)), deleter(Delete) {}
  SharedPointer(T *raw_ptr)
      : ptr(raw_ptr), ref_count(new size_t(1)), deleter(Delete<T>) {}
  SharedPointer(const SharedPointer &sp)
      : ptr(sp.ptr), ref_count(sp.ref_count), deleter(sp.deleter) {
    ++*ref_count;
  }
  SharedPointer &operator=(const SharedPointer &rhs) {
    if (this != &rhs) {
      decrement_and_destory();
      ptr = rhs.ptr;
      ref_count = rhs.ref_count;
      ++*ref_count;
      deleter = rhs.deleter;
    }
    return *this;
  }
  ~SharedPointer() { decrement_and_destory(); }

  operator bool() const { return ptr ? true : false; }
  T &operator*() const { return *ptr; }
  T *operator->() const { return ptr; }
  size_t use_count() const { return *ref_count; }
  T *get() const { return ptr; }
  bool unique() const { return *ref_count == 1; }
  void reset() { decrement_and_destory(); }
  void reset(T *pointer) {
    if (ptr != pointer) {
      decrement_and_destory();
      ptr = pointer;
      ref_count = new std::size_t(1);
    }
  }
  void reset(T *pointer, const std::function<void(T *)> &d) {
    reset(pointer);
    deleter = d;
  }

 private:
  T *ptr;
  size_t *ref_count;
  std::function<void(T *)> deleter;

  void decrement_and_destory() {
    if (ptr && --*ref_count == 0) {
      delete ptr;
      delete ref_count;
    } else if (!ptr) {
      delete ref_count;
    }
    ref_count = nullptr;
    ptr = nullptr;
  }
};

#endif