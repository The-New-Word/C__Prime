//
// Created by wan on 17-8-18.
//
#include "Header.h"

void x() {
    cout << "sss";
}

void print(int (&x)[6]) {
    for (auto temp: x) {
        cout << temp << endl;
    }
}

void print2(const int *beg, const int *end) {
    for (auto temp = beg; temp != end; temp++) {
        cout << *temp << endl;
    }
}

int *get(int length) {
    auto *nums = new int[length];//此方法最好避免使用,极容易出现内存泄漏问题,可以使用引用作为参数传入或是智能指针
    for (int *i = nums; i != nums + length; i++) {
        *i = length;
    }
    return nums;
}

void get(int (&nums)[10]) {
    for (auto &temp: nums) {
        temp = 10;
    }
}

size_t slength(const string &string1) {
    return string1.size();
}

void printLength(size_t (*pointer)(const string &), string string1) {
    size_t len = pointer(string1);
    cout << len << endl;

}
