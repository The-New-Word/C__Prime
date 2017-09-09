//
// Created by wan on 17-8-27.
//

#ifndef C_PRIME_STRBLOB_H
#define C_PRIME_STRBLOB_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class StrBlobPtr;

class strBlob {
    friend class StrBlobPtr;

    friend ostream &operator<<(ostream &, const strBlob &);

public:
    typedef vector<string>::size_type size_type;

    bool operator==(const strBlob &);

    bool operator!=(const strBlob &);

    StrBlobPtr begin();

    StrBlobPtr end();

    strBlob();

    strBlob(initializer_list<string> il);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const string &t) {
        data->push_back(t);
    }

    void push_back(string &&t) {
        data->push_back(move(t));
    }

    void pop_back();

    string &front();

    string &back();

private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};


#endif //C_PRIME_STRBLOB_H
