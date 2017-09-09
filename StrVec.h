//
// Created by wan on 17-9-2.
//

#ifndef C_PRIME_STRVEC_H
#define C_PRIME_STRVEC_H

#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &);

    StrVec &operator=(const StrVec &);

    StrVec &operator=(StrVec &&)noexcept;

    StrVec(StrVec &&s)noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
        s.elements = s.first_free = s.cap = nullptr;
    }

    ~StrVec();

    void push_back(const string &);

    void push_back(string &&);

    size_t size() const { return first_free - elements; }//返回已用空间大小

    size_t capacity() const { return cap - elements; }//返回总空间大小
    string *begin() const { return elements; }//返回首元素
    string *end() const { return first_free; }//返回尾元素

    string &operator[](size_t);

    const string &operator[](const size_t) const;

private:
    static allocator<string> alloc;//分配内存空间

    void chk_n_alloc() {
        if (size() == capacity()) {//当已用空间和总空间大小一致时重新分陪空间
            reallocate();
        }
    }
    //工具函数,被拷贝构造函数,赋值运算符和析构函数所使用

    pair<string *, string *> alloc_n_copy(const string *, const string *);

    void free();//销毁元素并释放内存空间
    void reallocate();//获得更多内存并拷贝已有元素
    string *elements;//指向数组首元素的指针
    string *first_free;//指向数组第一个空闲元素的指针
    string *cap;//指向数组尾后位置的指针
};


#endif //C_PRIME_STRVEC_H
