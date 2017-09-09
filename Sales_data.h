//
// Created by wan on 17-8-19.
//

#ifndef C_PRIME_SALES_DATA_H
#define C_PRIME_SALES_DATA_H

#include <iostream>
#include <utility>

using namespace std;

class Sales_data {

    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend ostream &print(ostream &, const Sales_data &);

    friend istream &read(istream &, Sales_data &);

    friend istream &operator>>(istream &, Sales_data &);//input

    friend ostream &operator<<(ostream &, Sales_data &);//output

    friend Sales_data &operator+(const Sales_data &, const Sales_data &);//add
    //算数运算符先将一边的值拷贝一份在进行运算处理

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    int b = 145;
    double avg_price() const;

public:
    Sales_data() : Sales_data("", 0, 0) { cout << "Sales_data()" << endl; }//委托构造函数

    explicit operator string() const;

    explicit Sales_data(string s) : Sales_data(std::move(s), 0, 0) { cout << "Sales_data(string s)" << endl; }//委托构造函数

    explicit Sales_data(istream &is) : Sales_data() {
        read(is, *this);
        cout << "Sales_data(istream &is)" << endl;
    }//委托构造函数

    Sales_data(string s, unsigned n, double p) :
            bookNo(std::move(s)), units_sold(n), revenue(p * n) {
        cout << "Sales_data(string s, unsigned n, double p)" << endl;
    }

    string isbn() const { return bookNo; }

    Sales_data &operator=(const string &);

    Sales_data &combine(const Sales_data &);

    Sales_data &operator+=(const Sales_data &);
};


#endif //C_PRIME_SALES_DATA_H
