//
// Created by wan on 17-8-14.
//

#include "Header.h"

int day4() {

    /* int a = 4, b = 7;
     double c = static_cast<double>(a) / b;//static_cast<>可以强制类型转换所有非底层const
     void *p = &a;
     auto *pa = static_cast<int *>(p);
     cout << *pa;
     char ch[6] = "aaaaa";
     const char *pc = ch;
     auto *p1 = const_cast<char *>(pc);//const_cast<>只可用于const
 */
    int x[] = {1, 2, 3, 4, 5, 6};
    int y[][3] = {
            1, 2, 3, 4, 5, 6
    };
    print2(begin(y[0]), end(y[1]));

    cout << "end" << endl;
    int length = 20;
    int *pointer = get(length);
    for (int *i = pointer; i != pointer + length; i++) {
        cout << *i << endl;
    }
    delete[] pointer;
    int nums[10];

    get(nums);
    cout << nums[0] << endl;
    cout << shortString("11111", "2222") << endl;
    size_t (*len)(const string &) = nullptr;//函数指针,返回类型与形参列表要与想调用的函数相一致

    string string1 = "asdhuhsahda";
    printLength(&slength, string1);


    return 0;
}