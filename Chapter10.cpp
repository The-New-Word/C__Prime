//
// Created by wan on 17-8-24.
//
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <iterator>
#include <sstream>
#include <fstream>

using namespace std;

void read(vector<string> &rd) {
    string line;
    getline(cin, line);
    string buf;
    istringstream is(line);
    while (is >> buf) {
        rd.push_back(buf);
    }

}

void C10_Test() {
    vector<int> vector1;
    int num;
    while (cin >> num) {
        vector1.push_back(num);
    }
    int x;
    cin.clear();
    cin.get();
    cout << "1" << endl;
    cin >> x;
    cout << "2" << endl;
    auto times = count(vector1.cbegin(), vector1.cend(), x);
    cout << x << " 出现的次数: " << times << endl;
}

void C10_Test2() {
    vector<int> vector1{1, 5, 6, 7};
    auto sum = accumulate(vector1.cbegin(), vector1.cend(), 5);
    cout << sum << endl;
    vector<string> vector2{"aaa", "bbb"};
    auto sum2 = accumulate(vector2.cbegin(), vector2.cend(), static_cast<string>("ss"));
    cout << sum2 << endl;
}

void C10_Test3() {
    vector<int> vector1;
    fill_n(back_inserter(vector1), 10, 1);
    for (auto temp: vector1) {
        cout << temp << endl;
    }
    vector<int> vector2(10);
    copy(vector1.begin(), vector1.end(), vector2.begin());
    for (auto &temp: vector2) {
        temp++;
        cout << temp << endl;
    }
    int a1[]{1, 2, 3, 4, 5, 6};
    int a2[6];
    copy(begin(a1), end(a1), a2);

    fill_n(begin(a2), end(a2) - begin(a2), 0);
    for (auto temp:a2) {
        cout << temp << endl;
    }
}

bool isShoter(const string &s1, const string &s2) {
    return s1.size() < s2.size();

}

void elimDups(vector<string> &words) {

    string line;
    getline(cin, line);
    istringstream read(line);
    string buf;
    while (read >> buf) {
        words.push_back(buf);
    }
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    for (const auto &temp: words) {
        cout << temp << endl;
    }
    cout << "开始排序" << endl;
    stable_sort(words.begin(), words.end(),
                [](const string &string1, const string &string2) { return string1.size() < string2.size(); });
    cout << "排序结束" << endl;
    for (const auto &temp: words) {
        cout << temp << endl;
    }
}

bool prediante(const string &s) {
    return s.size() >= 5;
}

void C10_Test5() {
    vector<string> vector1;
    string line;
    getline(cin, line);
    istringstream read(line);
    string buf;
    while (read >> buf) {
        vector1.push_back(buf);
    }
    auto pointer = partition(vector1.begin(), vector1.end(), prediante);
    for (auto p = vector1.begin(); p != pointer; p++) {
        cout << *p << endl;
    }
}

void C10_Test6() {
    vector<string> words;
    elimDups(words);
    int sz;
    cin >> sz;
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &string1) {
                          return string1.size() >= sz;
                      });

    for_each(wc, words.end(), [](const string &s) { cout << s << "  " << endl; });
}

void C10_Test7() {
    int nums = 10;
    auto get = [&]() -> bool {
        if (nums > 0) {
            nums--;
        } else {
            return false;
        }
        return true;
    };
    for (int i = 0; i < 100; i++) {
        cout << nums << endl;
        get();
    }
}

bool check_size(const string &string1, string::size_type size) {
    return string1.size() > size;
}

using namespace placeholders;

void C10_Test8() {
    int nums;
    vector<string> words;
    read(words);
    cin >> nums;
    auto check = bind(check_size, _1, nums);

    auto p = count_if(words.begin(), words.end(), check);
    cout << p << endl;
}

void C10_Test9() {
    vector<int> words{1, 5, 8, 7, 4, 6, 656, 5};
    auto bigger = [](int a, int b) -> bool {
        return a < b;
    };
    sort(words.begin(), words.end(), bigger);
    for (auto temp: words) {
        cout << temp << endl;
    }
    cout << "---------------------" << endl;
    sort(words.begin(), words.end(), bind(bigger, _2, _1));
    for (auto temp: words) {
        cout << temp << endl;
    }
}

void C10_Test10() {
    vector<string> words;
    read(words);
    sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
        return s1.size() < s2.size();
    });//排序
    auto pointer = unique(words.begin(), words.end());
    words.erase(pointer, words.end());//删除重复元素
    //  sort(words.begin(), words.end());
    for (auto &temp: words) {
        cout << temp << endl;
    }
    cin.clear();
    string::size_type nums;
    cin >> nums;
    auto pr = find_if(words.begin(), words.end(), bind(check_size, _1, nums));
    for_each(pr, words.end(), [](const string &temp) {
        cout << temp << endl;
    });
}

void C10_Test11() {
    vector<int> vector1{1, 1, 2, 2, 3, 4, 88, 8, 9, 11};
    vector<int> vector2;
    list<int> list3;
    vector<int> vector4;
    copy(vector1.begin(), vector1.end(), back_inserter(vector2));
    copy(vector1.begin(), vector1.end(), front_inserter(list3));
    copy(vector1.begin(), vector1.end(), inserter(vector4, vector4.begin()));
    cout << "v1:" << endl;
    for_each(vector1.begin(), vector1.end(), [](int i) {
        cout << i << endl;
    });
    cout << "v2:" << endl;
    for_each(vector2.begin(), vector2.end(), [](int i) {
        cout << i << endl;
    });
    cout << "l3:" << endl;
    for_each(list3.begin(), list3.end(), [](int i) {
        cout << i << endl;
    });
    cout << "v4:" << endl;
    for_each(vector4.begin(), vector4.end(), [](int i) {
        cout << i << endl;
    });

}

void C10_Test12() {
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    ostream_iterator<int> out_iter(cout, "  ");
    copy(vec.begin(), vec.end(), out_iter);//使用copy来打印输出
    cout << endl;
}


int day10() {
    vector<int> vector1{1, 2, 3, 8, 7};
    sort(vector1.begin(), vector1.end());
    for_each(vector1.begin(), vector1.end(), [](int i) {
        cout << i << endl;
    });
    reverse(vector1.begin(), vector1.end());
    for_each(vector1.begin(), vector1.end(), [](int i) {
        cout << i << endl;
    });
    return 0;
}

void homework1() {
    string file("wyx.txt");
    ifstream in(file);
    istream_iterator<string> istream_iterator1(in), eof;
    ostream_iterator<string> os(cout, "\n");
    vector<string> vector1;
    copy(istream_iterator1, eof, back_inserter(vector1));
    copy(vector1.cbegin(), vector1.cend(), os);
}

void homework2() {
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, "\n");
    vector<int> nums;
    vector<int> temp;
    copy(in, eof, back_inserter(temp));
    sort(temp.begin(), temp.end(), [](int a, int b) {
        return a > b;
    });
    unique_copy(temp.begin(), temp.end(), back_inserter(nums));
    copy(nums.begin(), nums.end(), out);
}

void homework3() {
    ifstream read_file("1.txt");
    istream_iterator<int> in(read_file), eof;
    ofstream out_file_odd("odd.txt"), out_file_even("even.txt");
    ostream_iterator<int> out_odd(out_file_odd, "\n"), out_even(out_file_even, "\n");


    for_each(in, eof, [&](int i) {
        if (i % 2 == 0) {
            //偶数
            *out_even++ = i;
        } else {
            *out_odd++ = i;
        }
    });
}