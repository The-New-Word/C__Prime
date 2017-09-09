//
// Created by wan on 17-8-29.
//

#ifndef C_PRIME_STRBLOBPTR_H
#define C_PRIME_STRBLOBPTR_H

#include <iostream>
#include <memory>
#include <vector>
#include "strBlob.h"

using namespace std;


class StrBlobPtr {
    friend ostream &operator<<(ostream &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0) {}

    explicit StrBlobPtr(strBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

//    StrBlobPtr(const StrBlobPtr &);

    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

    StrBlobPtr &operator++();//前置递增运算符

    StrBlobPtr operator++(int);//后置递增运算符

    StrBlobPtr &operator--();//前置递减运算符

    StrBlobPtr operator--(int);//后置递减运算符

    StrBlobPtr &operator+(size_t);//指针算术运算

    string &operator*() const;

    string *operator->() const;

    string &deref() const;

    StrBlobPtr &incr();

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;

    weak_ptr<vector<string>> wptr;
    size_t curr;


};


#endif //C_PRIME_STRBLOBPTR_H
