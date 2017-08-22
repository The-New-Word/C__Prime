//
// Created by wan on 17-8-19.
//

#include "Screen.h"

void Screen::some_member() const {
    ++access_ctr;//被声明为mutable类型的变量可以再在一个const对象中修改
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos width, pos height, char c) {
    contents[width * height] = c;
    return *this;
}
