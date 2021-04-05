#ifndef _WINDOW_MGR_H
#define _WINDOW_MGR_H

#include <vector>
#include <string>

class Screen;

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);

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

inline void Window_mgr::clear(ScreenIndex i)
{
    if (i >= screens.size())
        return;
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif