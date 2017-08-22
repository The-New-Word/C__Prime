//
// Created by wan on 17-8-20.
//

#ifndef C_PRIME_ACCOUNT_H
#define C_PRIME_ACCOUNT_H

#include <iostream>

using namespace std;


class Account {
private:
    string owner;
    double amount{};
    static double interestRate;

    static double initRate();

    static constexpr int period = 30;
    double daily_tbl[period]{};
public:

    Account() = default;

    void caculate() { amount += amount * interestRate; }

    static double rate() { return interestRate; }

    static void rate(double);

};

double Account::interestRate = 0;

double Account::initRate() {
    return 0;
}

#endif //C_PRIME_ACCOUNT_H
