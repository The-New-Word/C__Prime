//
// Created by wan on 17-8-22.
//
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <stack>

using namespace std;

bool find(vector<int>::iterator begin, vector<int>::iterator end, int i);

vector<int>::iterator find2(vector<int>::iterator begin, vector<int>::iterator end, int i);

void Test1() {
    vector<int> vector1;
    int n;
    cout << "nums:" << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vector1.push_back(temp);
    }
    auto begin = vector1.begin();
    auto end = vector1.end();
    int num;
    cout << "which you want to find?" << endl;
    cin >> num;
    cout << (find(begin, end, num) ? "found" : "not found") << endl;
}

void Test2() {
    //6 ways to create the vector
    vector<int> vector1(10);
    vector<int> vector2;
    vector<int> vector3(10, 1);
    vector<int> vector4{1, 2, 3};
    vector<int> vector5(vector1);
    vector<int> vector6(vector1.begin(), vector1.end());

    array<int, 4> array{};
    for (auto &temp: array) {
        temp = 1;
    }
    cout << array[3] << endl;
}

void Test3() {
    list<int> list1{1, 2, 5};
    vector<double> vector1(list1.begin(), list1.end());
    list<const char *> list2{"aa", "bb"};
    vector<string> vector2;
    vector2.assign(list2.begin(), list2.end());
    int nums;
    list<int> list3;
    auto begin = list3.begin();
    while (cin >> nums) {
        begin = list3.insert(begin, nums);//equals to list3.push_front(nums)
    }
    for (auto temp:list3) { cout << temp << endl; }
    list3.emplace_back(3);
}

void Test4() {
    deque<string> cache;
    string string1;
    while (cin >> string1) {
        if (string1 == "break") {
            break;
        }
        cache.push_back(string1);
    }

    for (auto &begin : cache) {
        cout << begin << endl;
    }
}

void Test5() {
    list<int> nums{1, 57, 6, 8, 4, 2, 3, 151, 2, 66, 47, 88, 9};
    deque<int> odd;
    deque<int> even;
    for (auto &temp: nums) {
        if (temp % 2 == 0) {
            even.push_back(temp);
        } else {
            odd.push_back(temp);
        }
    }
    cout << "odd:" << endl;
    for (auto temp:odd) { cout << temp << endl; }
    cout << "even:" << endl;
    for (auto temp:even) { cout << temp << endl; }
}

void Test6() {
    list<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = nums.begin();
    while (it != nums.end()) {
        if (*it % 2 != 0) {
            it = nums.erase(it);//返回被删除元素之后的一个迭代器
        } else {
            it++;
        }
    }
    for (auto temp:nums) {
        cout << temp << endl;
    }
}

void Test7() {
    int ia[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> odd(begin(ia), end(ia));//删除偶数
    list<int> even(begin(ia), end(ia));//删除奇数
    auto p1 = odd.begin();
    auto p2 = even.begin();

    while (p1 != odd.end() || p2 != even.end()) {
        if (p1 != odd.end()) {
            if (*p1 % 2 == 0) {
                p1 = odd.erase(p1);
            } else {
                p1++;
            }
        }
        if (p2 != even.end()) {
            if (*p2 % 2 == 1) {
                p2 = even.erase(p2);

            } else {
                p2++;
            }
        }
    }
    cout << "奇数:" << endl;
    for (auto temp: odd) {
        cout << temp << endl;
    }
    cout << "偶数:" << endl;
    for (auto temp: even) {
        cout << temp << endl;
    }
}

void Test8() {
    forward_list<int> fl{1, 2, 3, 4, 5, 6, 7, 98, 10};
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while (curr != fl.end()) {
        if (*curr % 2 != 0) {
            curr = fl.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
}


int day9() {



    return 0;
}

bool find(vector<int>::iterator begin, vector<int>::iterator end, int i) {
    cout << "begin find..." << endl;
    while (begin != end) {
        if (*begin == i) {
            return true;
        }
        begin++;
    }
    return false;
}

vector<int>::iterator find2(vector<int>::iterator begin, vector<int>::iterator end, int i) {
    cout << "begin find..." << endl;
    while (begin != end) {
        if (*begin == i) {
            return begin;
        }
        begin++;
    }
    return end;
}