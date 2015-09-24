#include "stdafx.h"
#include "screen.h"
#include "window_mgr.h"

Window_mgr::Window_mgr() {
    screens.push_back(Screen(24, 80, ' '));
}

void Window_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    s.contents = std::string(s.width * s.height, ' ');
}