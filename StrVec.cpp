//
// Created by wan on 17-9-2.
//

#include "StrVec.h"

allocator<string> StrVec::alloc;


pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);//返回分配的内存空间的首元素
    auto end = uninitialized_copy(b, e, data);//复制元素并返回尾元素
    return {data, end};

}

void StrVec::free() {
    if (elements) {
        //逆序销毁旧元素
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);//注意是--p,因为p指向的始终是第一个未被构造的指针,而不是最后一个构造的指针!
        }
        alloc.deallocate(elements, cap - elements);//释放空间
    }

}

StrVec::StrVec(const StrVec &vec) {
    auto new_data = alloc_n_copy(vec.begin(), vec.end());//返回指针pair,first指向的是第一个构造的元素,second指向的是最后一个构造的元素
    elements = new_data.first;
    first_free = cap = new_data.second;

}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &vec) {
    auto data = alloc_n_copy(vec.begin(), vec.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);//分配新的内存空间,并返回第一个未构造的指针
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);//移动元素
    free();//一旦完成移动就释放就内存空间
    //更新我们的数据结构
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

//移动运算符
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {//检测自赋值
        free();//释放已有元素
        elements = rhs.elements;//从rhs中接管资源
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;

}

void StrVec::push_back(string &&s) {
    chk_n_alloc();//确保内存空间
    alloc.construct(first_free++, move(s));

}

void StrVec::push_back(const string &str) {
    chk_n_alloc();//确保有空间容纳元素
    alloc.construct(first_free++, str);//在第一个空闲指针处构造str的副本
    //因为内存是未构造的原始内存,所以必须要先构造

}

string &StrVec::operator[](size_t n) {
    return elements[n];//用于给元素赋值
}

const string &StrVec::operator[](const size_t n) const {
    return elements[n];//获取元素的值
}
