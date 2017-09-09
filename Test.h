/*
//
// Created by wan on 17-8-30.
//

#ifndef C_PRIME_TEST_H
#define C_PRIME_TEST_H


#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class StrBlobPtr;

class strBlob {
public:
    typedef vector<string>::size_type size_type;

    friend class StrBlobPtr;

    StrBlobPtr begin();

    StrBlobPtr end();

    strBlob();

    strBlob(initializer_list<string> il);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const string &t) {
        data->push_back(t);
    }

    void pop_back();

    string &front();

    string &back();

private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};


class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}

    StrBlobPtr(strBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

    string &deref() const;

    StrBlobPtr &incr();

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;

    weak_ptr<vector<string>> wptr;
    size_t curr;


};


#endif //C_PRIME_TEST_H
*/
