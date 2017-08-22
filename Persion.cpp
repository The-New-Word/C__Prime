//
// Created by wan on 17-8-19.
//

#include "Persion.h"

#include <utility>

string Persion::GetName() const {

    return this->name;
}

string Persion::GetAddress() const {
    return this->address;
}

void Persion::SetName(string name) {
    this->name = std::move(name);

}

void Persion::SetAddress(string address) {
    this->address = std::move(address);
}
