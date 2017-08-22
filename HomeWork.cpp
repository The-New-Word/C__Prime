//
// Created by wan on 17-8-18.
//

#include "HomeHead.h"

/*int main() {
    vector<fun> vector1;
    int (*pointer1)(int, int) = nullptr;
    pointer1 = Add;
    vector1.push_back(pointer1);
    pointer1 = Minus;
    vector1.push_back(pointer1);
    for (auto temp: vector1) {
        int value = temp(5, 6);
        cout << value << endl;
    }
    return 0;
}*/

int Add(int a, int b) {
    return a + b;
}

int Minus(int a, int b) {
    return a - b;
}
