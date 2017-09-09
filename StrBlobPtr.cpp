//
// Created by wan on 17-8-29.
//

#include "StrBlobPtr.h"

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string &msg) const {
    auto ret = wptr.lock();//检查vector是否依然存在
    if (!ret) {
        //如果不存在
        throw runtime_error("unbound StrBlobPtr!");//抛出异常,未绑定的指针
    }
    if (sz >= ret->size()) {
        //检查给定的索引是否正确
        throw out_of_range(msg);

    }
    return ret;

}

//解引用
string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end!");
    return (*p)[curr];//*p是对象所指向的vector
}

//前缀递增,返回递增后的解引用
StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "incerement past end of StrBlobPtr!");
    ++curr;
    return *this;

}

StrBlobPtr &StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");//检查是否已经到达末尾
    curr++;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
    curr--;//与递增操作不同,先进行递减操作,如果越过0就会产生异常
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    //后置的运算符必须要先保存原始值
    StrBlobPtr old = *this;
    --*this;//调用前置递减
    return old;//将原始值返回
}

StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr old = *this;
    ++*this;//注意:必须调用前置的,如果使用后置的会导致无限递归
    return old;
}

StrBlobPtr &StrBlobPtr::operator+(size_t n) {
    auto temp = make_shared<StrBlobPtr>(*this);
    for (size_t i = 0; i < n; i++) {
        ++*temp;
    }
    return *temp;

}

StrBlobPtr strBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr strBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

ostream &operator<<(ostream &os, const StrBlobPtr &ptr) {
    auto element = ptr.check(ptr.curr, "IO read Exception!");
    os << (*element)[ptr.curr];
    return os;
}

string &StrBlobPtr::operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
//p->x等价于(*p).x

string *StrBlobPtr::operator->() const {
    return &this->operator*();
}
/*
StrBlobPtr::StrBlobPtr(const StrBlobPtr &temp) {
    this->curr = temp.curr;
    this->wptr = temp.wptr;


}*/
