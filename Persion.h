//
// Created by wan on 17-8-19.
//

#ifndef C_PRIME_PERSION_H
#define C_PRIME_PERSION_H

#include <iostream>
#include <utility>

using namespace std;

class Persion {
private:
    string name;
    string address;
public:
    Persion() : Persion("", "") {}

    Persion(string name, string address) :
            name(std::move(name)), address(std::move(address)) {}

    explicit Persion(string name) : Persion(std::move(name), "") {}

    string GetName() const;

    string GetAddress() const;

    void SetName(string);

    void SetAddress(string);

};


#endif //C_PRIME_PERSION_H
