//
// Created by wan on 17-8-11.
//
#include <iostream>

using namespace std;
int j = 0;
constexpr int i = 42;

int Day2() {
    /* int ival = 1024;
     int *p = &ival;
     int **ppi = &p;
     int *&r = p;//r是一个指针的引用
     int i = 12;
     r = &i;//修改了p所指向的地址,因为r是p的引用,所以同时p也指向了i
     *r = 44;//修改了i的值
     cout << ival << endl;
     cout << i << endl;
     cout << *p << endl;
     cout << **ppi << endl;*/

    //--------------------------------
    /*const int a = 7;//const常量必须初始化
    const int *p = &a;//要让指针指向常量,就只能用常量指针
    //extern int b;//extern 关键字表示该变量或常量的定义在别的文件中
    int x = 4;
    int *const pointer = &x;//常量指针,该指针所指向的地址不可更改
    const int &b = x;//x的值可以修改,但是引用b不可以修改,相当于只读
    const int *const q = &a;
    x = 45;
    cout << b;*/

    //--------------------------------
    /*constexpr int *np = nullptr;

    constexpr const int *p = &i;
    constexpr int *p1 = &j;
    */

    //--------------------------------
/*]
    typedef double wages;//关键字typedef可以为类型起别名,此处,wages等价于double
    wages a = 4.2;
    cout << a << endl;
    typedef wages *p;//p等价于wages * 等价于double *
    p pointer = &a;
    cout << *pointer << endl;

    using integer=int;//和typedef用法一致
    integer x = 45;
    */
    //--------------------------------
/*
    int i = 44;//通过值,自动推测变量类型,注意使用auto必须初始化变量,auto会忽略顶层const
    auto a = 8.33;
    cout << a << endl;
    const int x = 45;
    const int ci = 0;
    auto &n = i;
    auto &g = ci;
    auto *p2 = &ci;
    auto e = &ci;*/
/*
    const int i = 42;
    int m = 99;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    j = 77;
    p = &m;

    cout << j << endl;
    cout << k << endl;
    cout << *p << endl;
    cout << j2 << endl;
    cout << k2 << endl;*/

    //-------------------------

    const int ci = 0, &cj = ci;
    int c = 0;
    int d = 4;
    decltype(ci) x = 0;//与auto相似,但处理顶层const,初始化条件与推测出来的类型是否要初始化一致
    decltype(c) j;
    decltype((c)) j2 = c;//如果加上了一个括号,就变成了引用
    decltype(c=d) j3 = c;//也是引用

    return 0;
}

