//
// Created by wan on 17-8-19.
//

#include "Sales_data.h"

double Sales_data::avg_price() const {
    if (units_sold != 0u) {
        return revenue / units_sold;
    }
    return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}



istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << "isbn" << item.isbn() << " units_sold " << item.units_sold << " revenue " << item.revenue << " avg_price "
       << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &ihs, const Sales_data &rhs) {
    Sales_data sum = ihs;
    sum.combine(rhs);
    return sum;
}