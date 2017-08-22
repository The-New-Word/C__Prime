//
// Created by wan on 17-8-19.
//

#ifndef C_PRIME_WINDOW_MGR_H
#define C_PRIME_WINDOW_MGR_H

#include <iostream>
#include <vector>
#include "Screen.h"


using namespace std;
using pos = string::size_type;

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;

    void clear(ScreenIndex);//Screen的友元方法

    ScreenIndex addScreen(const Screen &);

    Window_mgr() = default;

    Window_mgr(pos width, pos height);

    Window_mgr(pos width, pos height, char c);

private:
    vector<Screen> screens{Screen(24, 80, ' ')};


};


#endif //C_PRIME_WINDOW_MGR_H
