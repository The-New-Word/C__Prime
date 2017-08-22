//
// Created by wan on 17-8-19.
//

#include "Window_mgr.h"

Window_mgr::Window_mgr(pos width, pos height) {
    Screen screen(width, height, ' ');
    screens.push_back(screen);
}

Window_mgr::Window_mgr(pos width, pos height, char c) {
    Screen screen(width, height, c);
    screens.push_back(screen);
}

void Window_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    s.contents = string(s.height * s.width, ' ');

}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &screen) {
    screens.push_back(screen);

    return screens.size() - 1;
}
