//
// Created by wan on 17-8-19.
//

#ifndef C_PRIME_SCREEN_H
#define C_PRIME_SCREEN_H

#include <iostream>


using namespace std;

class Screen {

    friend class Window_mgr;
public:

    using pos = string::size_type;//必须先定义后才可使用
    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}//string类型的另一种初始化方法表示ht*wd个c

    char get() const {
        return contents[cursor];
    }

    Screen &move(pos r, pos c);

    inline char get(pos r, pos c) const;

    void some_member() const;

    Screen &set(char);

    Screen &set(pos, pos, char);

    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr{};

    void do_display(ostream &os) const { os << contents; }

};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

#endif //C_PRIME_SCREEN_H
