//
// Created by wan on 17-8-27.
//

#include "strBlob.h"

strBlob::strBlob() : data(make_shared<vector<string>>()) {}

strBlob::strBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void strBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string &strBlob::front() {
    check(0, "front on empty StrBlob!");
    return data->front();
}

string &strBlob::back() {
    check(0, "back on empty strBlob!");
    return data->back();
}

void strBlob::pop_back() {
    check(0, "pop_back on empty strBlob!");
    data->pop_back();
}


bool strBlob::operator==(const strBlob &strBlob1) {
    bool result = true;
    if (this->data->size() != strBlob1.data->size()) {
        result = false;
    } else {
        auto bg = this->data->begin();

        for_each(strBlob1.data->begin(), strBlob1.data->end(), [&](string i) {
            if (*bg != i) {
                result = false;
                bg++;
            }
        });
    }
    return result;
}

bool strBlob::operator!=(const strBlob &strBlob1) {
    return !(*this == strBlob1);
}

ostream &operator<<(ostream &os, const strBlob &sb) {
    for_each(sb.data->begin(), sb.data->end(), [&](string i) {
        os << i<<" ";
    });
    return os;
}
