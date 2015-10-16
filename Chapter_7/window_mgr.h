#pragma once
#include <vector>
#include <string>

class Screen;

class Window_mgr {
public:
    Window_mgr();
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};
