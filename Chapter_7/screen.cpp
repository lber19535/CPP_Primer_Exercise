#include "stdafx.h"
#include "screen.h"

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen &Screen::display(std::ostream &out)
{
    do_display(out);
    return *this;
}

