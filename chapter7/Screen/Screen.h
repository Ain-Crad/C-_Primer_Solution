#ifndef _SCREEN_H
#define _SCREEN_H

#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    Screen &move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen &set(char ch)
    {
        contents[cursor] = ch;
        return *this;
    }
    Screen &set(pos r, pos c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    };
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    };

private:
    void do_display(std::ostream &os) const { os << contents; }
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif