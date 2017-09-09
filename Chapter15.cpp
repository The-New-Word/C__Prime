//
// Created by wan on 17-9-7.
//

#include "Chapter15.h"

int main() {
    Limit_quote limitQuote("数字设计和计算机体系结构", 71.5, 3, 0.6);
    print_total(cout, limitQuote, 4);
    Quote *base = &limitQuote;
    limitQuote.debug();

    return 0;
}

double Bulk_quote::net_price(size_t n) const {
    if (n >= quantity) {
        return n * discount * price;
    } else {
        return n * price;
    }
}

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << " ISBN " << item.isbn() << " # sold: " << n << " total due: "
       << ret << endl;
    return ret;

}

double Limit_quote::net_price(size_t n) const {
    if (n <= quantity) {
        return n * discount * price;
    } else {
        return n * price;
    }
}
