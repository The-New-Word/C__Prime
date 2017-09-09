//
// Created by wan on 17-9-6.
//

#ifndef C_PRIME_CHAPTER14_H
#define C_PRIME_CHAPTER14_H

#include<iostream>
#include <utility>
#include "Sales_data.h"
#include "strBlob.h"
#include <algorithm>
#include "StrBlobPtr.h"
#include <sstream>
#include <functional>
#include <map>

using namespace std;
using namespace placeholders;

//注:
// 1.输出运算符必须是非成员函数,若果是一个成员函数则左侧运算对象将是我们类的一个对象
// 2.输入运算符需要处理可能失败的情况,而输出运算符则不需要!!
// 3.不论形参是什么,赋值运算符或复合赋值运算符都必须定义为成员函数
// 4.算术运算符与关系运算符都应定义为非成员函数,为了允许对象转换
// 5.下标运算符必须是成员函数;如果一个类需要下标运算符通常需要定义两个版本,一个返回普通引用(可以用于赋值),另一个是累的常量成员并且返回常量引用
// 6.递增或递减运算符最好设为成员函数;同时都应定义两个版本,一个为前置,一个为后置
// 7.函数调用运算符()必须是成员函数
class Book {
    friend istream &operator>>(istream &, Book &);

    friend ostream &operator<<(ostream &, const Book &);

    friend bool operator==(const Book &, const Book &);

    friend bool operator!=(const Book &, const Book &);

public:
    Book() = default;

    Book(string name, string author, double price, string publisher) : book_name(std::move(name)),
                                                                       book_author(move(author)),
                                                                       book_price(price),
                                                                       book_publisher(std::move(publisher)) {}

    explicit Book(istream &is) { is >> *this; }

private:
    string book_name;
    double book_price{};
    string book_author;
    string book_publisher;
};


class MyPointer {
public:
    MyPointer() = default;

    explicit MyPointer(StrBlobPtr *p) : p(p) {}

    StrBlobPtr &operator*() const;

    StrBlobPtr *operator->() const;

private:
    StrBlobPtr *p;
};

struct Judge {
    Judge() = default;

    int operator()(bool a, int b, int c);
};

class Smaller {
public:
    Smaller() = default;

    bool operator()(const int &a, const int &b);
};

class IsInRange {
public:
    IsInRange(size_t &l, size_t &u) : lower(l), upper(u) {}

    bool operator()(const string &s);

private:
    size_t lower;//下限
    size_t upper;//上限
};

void Word_length() {
    string word;
    getline(cin, word);
    cout << word << endl;
    istringstream in(word);
    vector<string> words_vec;
    string buff;
    while (in >> buff) {
        words_vec.push_back(buff);
    }
    for (size_t i = 1; i <= 10; i++) {

        int num = 0;
        IsInRange range(i, i);
        for_each(words_vec.begin(), words_vec.end(), [&](string s) {
            if (range(s)) {
                num++;
            }
        });
        cout << "长度为" << i << "的单词个数为:" << num << endl;
    }
}

class smallInt {
    friend ostream &operator<<(ostream &, const smallInt &);

public:
    explicit smallInt(int i = 0) : val(i) {
        if (i < 0 || i > 255) {
            throw out_of_range("wrong!");
        }
    }

    explicit operator int() const {
        return val;
    }

private:
    int val;
};

#endif //C_PRIME_CHAPTER14_H
