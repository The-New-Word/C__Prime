//
// Created by wan on 17-8-11.
//

#ifndef C_PRIME_HEADER_H
#define C_PRIME_HEADER_H

#include <iostream>

using namespace std;

void print(int (&x)[6]);

void x();

void print2(const int *beg, const int *end);

int *get(int);

void get(int (&nums)[10]);

string screen(int x, int hight = 10, int width = 4);//默认实参

inline const string &shortString(const string &s1, const string &s2) {
    return s1.size() > s2.size() ? s2 : s1;
}//内联函数,用于优化规模较小,流程直接,调用频繁的函数,注意内联函数只可在头文件中定义

size_t slength(const string &);

void printLength(size_t (*pointer)(const string &), string string1);//将函数指针作为形参

#endif //C_PRIME_HEADER_H
