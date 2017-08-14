//
// Created by wan on 17-8-11.
//
#include <iostream>
#include <vector>


using namespace std;

void readLine() {
    string s;
    getline(cin, s);
    cout << s << endl;
}

void readWord() {
    string word;
    while (cin >> word) {
        cout << word << endl;
    }
}

void readPunct() {
    string str("hello world!!!!");

    decltype(str.size()) nums = 0;
    for (auto temp: str) {
        if (ispunct(temp) != 0) {
            nums++;

        }
    }
    printf("一共有标点符号%lu\n", nums);
}

void Day3() {
    string s1 = "ss";//拷贝初始化
    string s2("value");//直接初始化
    string s3(10, 'd');//直接初始化
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    getline(cin, s2);
    if (s2.size() > 10) {
        cout << s2 << endl;
    }

    vector<int> vector1(10);//10个元素,每个元素初始化值为0
    vector<int> vector2(10, 1);//10个元素,每个元素的值为1
    vector<int> vector3{10};//1个元素,初始值为10
    vector<int> vector4{10, 1};//2个元素,一个10一个1
    vector<string> vector5(10, "ssss");
}

void toUpper(string &s) {
    for (auto &temp: s) {
        temp = static_cast<char>(toupper(temp));//temp为引用,改变temp的值就会改变原来的值
    }
}

void deletePunct(string &string1) {
    string string2;
    for (auto temp: string1) {
        if (ispunct(temp) == 0) {
            string2 += temp;
        }
    }
    string1 = string2;

}

void readScorse() {
    vector<unsigned> scores(10, 0);
    int num;
    while (cin >> num) {
        if (num >= 0 && num <= 100)
            scores[num / 10]++;
    }
    for (auto temp: scores) {
        cout << temp << endl;
    }

}

bool BinarySearch(int search, vector<int> nums) {
    auto begin = nums.begin(), end = nums.end();
    auto mid = nums.begin() + nums.size() / 2;
    while (mid != end && *mid != search) {
        if (search < *mid) {
            end = mid;
        } else {
            begin = mid;
        }
        mid = begin + (end - begin) / 2;
    }
    return *mid == search;
}

int get() {
    return 1;
}

int main() {
    int t[get()];
    size_t index = 0;//数组下标一般定义为size_t类型
    int a[] = {4, 8, 9};
    int b[3];
//    b = a; 注意:不可以把一个数组的值直接复制给另一个数组
    int (*pointer1)[3] = &a;//指向大小为3的数组指针
    int (&pointer2)[3] = a;//引用大小为3的数组引用
    cout << *pointer2 * 8 << endl;
    cout << pointer1 << "    " << *pointer1 << "    " <<
         **pointer1 << endl;
    for (int *p = begin(a); p != end(a); p++) {
        cout << *p << endl;
    }
    auto size = end(a) - begin(a);
    cout << size << endl;
    cout << *(a + 2) << endl;
    string s = "abcdefx";
    const char *str = s.c_str();
    vector<int> vector1(begin(a), end(a));//允许用数组初始化vector,但反之则不行,参数为地址
    int array[][3] = {
            1, 2, 3, 4, 5, 6
    };
    for (auto &temp: array) {
        for (auto temp1: temp) {
            cout << temp1 << endl;
        }
    }
    auto p = begin(array);
    cout << **p;

    return 0;
}
