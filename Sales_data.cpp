//
// Created by wan on 17-8-19.
//

#include <memory>
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

istream &operator>>(istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = price * item.units_sold;

    } else {
        item = Sales_data();
    }
    return is;
}

ostream &operator<<(ostream &os, Sales_data &item) {
    os << "isbn :" << item.isbn() << " units_sold: " << item.units_sold << " revenue: " << item.revenue
       << " avg_price: "
       << item.avg_price();
    return os;

}

Sales_data &operator+(const Sales_data &item1, const Sales_data &item2) {
    auto item3 = make_shared<Sales_data>(item1);
    (*item3).combine(item2);
    return *item3;

}

Sales_data &Sales_data::operator+=(const Sales_data &item) {
    *this = *this + item;
    return *this;

}

Sales_data &Sales_data::operator=(const string &ISBN) {
    *this = Sales_data(ISBN);
    return *this;

}

Sales_data::operator string() const {

    return bookNo;
}
