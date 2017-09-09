//
// Created by wan on 17-9-7.
//

#ifndef C_PRIME_CHAPTER15_H
#define C_PRIME_CHAPTER15_H

#include <iostream>
#include <utility>

// 面向对象:
// 1.数据抽象(封装):实现类的接口与实现分离
// 2.继承:构成层次关系;基类(父类)->派生类(子类)
// 3.虚函数:基类希望派生类个自定义适合自身的版本
// 4.动态绑定(多态):以统一的方式使用从同一个基类派生出的派生类
// 5.作为基类一般都会定义一个虚析构函数
// 6.每个类控制自己的成员初始化的过程,派生类调用基类构造器来初始化基类的成员
using namespace std;

class Quote {
public:
    Quote() = default;

    Quote(string book, double sales_price) : bookNo(std::move(book)), price(sales_price) {}

    string isbn() const { return bookNo; }

    virtual void debug() {
        cout << "ISBN: " << this->isbn() << " Price: " << this->price << endl;
    }

    virtual double net_price(size_t n) const {
        return n * price;
    }

    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n);

class Disc_quote : public Quote {//含有纯虚函数的基类是抽象基类,不可实例化对象
public:
    Disc_quote() = default;

    Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), quantity(qty),
                                                                            discount(disc) {}

    double net_price(size_t) const override =0;//纯虚函数,没有任何定义

protected:
    size_t quantity = 0;//折扣使用的数量
    double discount = 0.0;//折扣


};

class Bulk_quote : public Disc_quote {//继承
public:
    Bulk_quote() = default;

    Bulk_quote(const string &book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {};

    double net_price(size_t n) const override;

    void debug() override {
        Quote::debug();
        cout << "quantity: " << this->quantity << " discount: " << this->discount << endl;
    }

};

class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;

    Limit_quote(const string &book, double price, size_t num, double dis) : Disc_quote(book, price, num, dis) {}

    void debug() override {
        Quote::debug();
        cout << "quantity: " << this->quantity << " discount: " << this->discount << endl;
    }

    double net_price(size_t n) const override;

};

class People {
public:
    People() = default;

    People(string name, size_t age, string sex) : name(std::move(name)), age(age),
                                                  sex(move(sex)) {}

    virtual void print() {
        cout << "name:" << name << " age: " << age << " sex: " << sex;
    }

private:
    string name;
    size_t age;
    string sex;

};

class Student : public People {
public:
    Student() = default;

    Student(string name, size_t age, string sex) : People(move(name), age, move(sex)) {}

    void print() override {
        People::print();
        cout << "\nI'm ...." << endl;
    }

private:

};

#endif //C_PRIME_CHAPTER15_H
