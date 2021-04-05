#include <iostream>
#include <memory>
#include <string>

template <typename T, typename... Args>
auto MakeShared(Args &&... args) -> std::shared_ptr<T> {
  return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

struct Foo {
  explicit Foo(int b) : bar(b) {}
  int bar;
};

int main() {
  auto num = MakeShared<int>(42);
  std::cout << *num << std::endl;

  auto str = MakeShared<std::string>(10, 'c');
  std::cout << *str << std::endl;

  auto foo = MakeShared<Foo>(100);
  std::cout << foo->bar << std::endl;

  return 0;
}