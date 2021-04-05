#ifndef _SCREEN_H
#define _SCREEN_H

#include <iostream>
#include <string>

template <unsigned, unsigned> class Screen;

template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &sc);
template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &sc);

template <unsigned H, unsigned W> class Screen {
  friend std::ostream &operator<<<H, W>(std::ostream &os, const Screen &sc);
  friend std::istream &operator>><H, W>(std::istream &is, Screen &sc);

public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(char c) : contents(H * W, c) {}
  char get() const { return contents[cursor]; }
  Screen &move(pos r, pos c);

private:
  pos cursor = 0;
  pos height = H, width = W;
  std::string contents;
};

template <unsigned H, unsigned W>
Screen<H, W> &Screen<H, W>::move(pos r, pos c) {
  cursor = r * width + c;
  return *this;
}

template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &sc) {
  os << sc.contents;
  return os;
}

template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &sc) {
  char c;
  is >> c;
  std::string temp(H * W, c);
  sc.contents = temp;
  return is;
}

#endif