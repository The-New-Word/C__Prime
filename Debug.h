//
// Created by wan on 17-8-20.
//

#ifndef C_PRIME_DEBUG_H
#define C_PRIME_DEBUG_H

#include <iostream>

using namespace std;


class Debug {
private:
    bool hw;
    bool io;
    bool other;
public:
    constexpr explicit Debug(bool b) : hw(b), io(b), other(b) {}

    constexpr Debug(bool hw, bool io, bool other) : hw(hw), io(io), other(other) {}

    constexpr bool any() { return hw || io || other; }

    void set_io(bool b) { io = b; }

    void set_hw(bool b) { hw = b; }

    void set_other(bool b) { other = b; }
};


#endif //C_PRIME_DEBUG_H
