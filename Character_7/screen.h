#pragma once
#include <string>
#include <iostream>
#include "window_mgr.h"

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd,' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c){}
    char get() const{
        return contents[cursor];
    }
    char get(pos ht, pos wd) const;
    Screen &set(char c);
    Screen &set(pos r, pos col, char c);
    Screen &move(pos r, pos c);

    Screen &display(std::ostream &cout);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &out);
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    cursor++;
    return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
}

inline void Screen::do_display(std::ostream &out) {
    out << contents << std::endl;
}

