//
// Created by wan on 17-9-6.
//

#include "Chapter14.h"

void Ch_Test1() {
    strBlob strBlob1;
    strBlob strBlob2;
    strBlob1.push_back("ssss2");
    strBlob2.push_back("ssss");
    if (strBlob1 == strBlob2) {
        cout << strBlob1 << endl;
    }
    strBlob1.push_back("11111");
    strBlob1.push_back("22222");
    strBlob1.push_back("33333");

    StrBlobPtr ptr(strBlob1);

    for (auto bg = strBlob1.begin(); bg != strBlob1.end(); bg++) {
        cout << bg << endl;
    }
}

void Ch_Test2() {
    strBlob a1 = {"h1", "h2", "now"};
    StrBlobPtr p(a1);
    cout << a1 << endl;
    cout << p + 2 << endl;
    *p = "ok";
    for (size_t i = 0; i < p->size(); i++) {
        cout << p + i << endl;
    }
    cout << p->size() << endl;
    cout << (*p).size() << endl;
    MyPointer myPointer(&p);
    cout << *myPointer << endl;
}

void Ch_Test3() {
    vector<int> nums;
    for (int i = 0; i < 100; i++) {
        nums.push_back(rand() % 1000);
    }

    sort(nums.begin(), nums.end(), Smaller());
    for_each(nums.begin(), nums.end(), [](int i) {
        cout << i << endl;
    });
}

void Ch_Test4() {
    vector<int> s{1, 2, 3, 4, 5, 6, 7};
    vector<int> copy(s.size());
    vector<string> s_vec{"pooh", "ooo"};
    auto nums = count_if(s.begin(), s.end(), bind(greater<int>(), _1, 3));
    cout << nums << endl;
    auto str = find_if(s_vec.begin(), s_vec.end(), bind(not_equal_to<string>(), _1, "pooh"));
    cout << *str << endl;
    transform(s.begin(), s.end(), copy.begin(), bind(multiplies<int>(), _1, 3));
    //cout << "sss";
    for_each(copy.begin(), copy.end(), [](int i) {
        cout << i << endl;
    });
}

void Ch_Test5() {

    auto data = {1, 2, 3, 4, 5, 6, 7};
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicator = [&](int i) {
        return 0 == mod(input, i);
    };
    auto is_divisible = std::all_of(data.begin(), data.end(), predicator);
    std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;
}

int ch14() {
    /* smallInt s(15);
     s = static_cast<int>(s) + 15;
     cout << s << endl;
 */
    Sales_data sales_data{"sad"};
    string s = static_cast<string>(sales_data);
    cout << s << endl;
    return 0;
}

void Easy_Caculate() {
    map<string, function<int(int, int)>> caculate;
    function<int(int, int)> add = [](int a, int b) {
        return a + b;
    };
    function<int(int, int)> minuse = [](int a, int b) {
        return a - b;
    };
    function<int(int, int)> multiply = multiplies<int>();
    function<int(int, int)> divide = divides<int>();
    caculate.insert({"+", add});
    caculate.insert({"-", minuse});
    caculate.insert({"/", divide});
    caculate.insert({"*", multiply});

    string sym;
    cin >> sym;
    int a, b;
    cin >> a >> b;
    cout << caculate[sym](a, b) << endl;

}

istream &operator>>(istream &is, Book &book) {
    is >> book.book_name >> book.book_price >> book.book_author >> book.book_publisher;
    if (!is) {
        book = Book();
    }
    return is;
}

ostream &operator<<(ostream &os, const Book &book) {
    os << "书名: " << book.book_name << " 价格: " << book.book_price << " 作者: " << book.book_author << " 出版社: "
       << book.book_publisher;

    return os;
}

bool operator==(const Book &b1, const Book &b2) {
    return b1.book_name == b2.book_name && b1.book_publisher == b2.book_publisher && b1.book_author == b2.book_author &&
           b1.book_price == b2.book_price;
}

bool operator!=(const Book &b1, const Book &b2) {
    return !(b1 == b2);
}

StrBlobPtr &MyPointer::operator*() const {
    return *p;
}

StrBlobPtr *MyPointer::operator->() const {
    return (*this).p;
}

int Judge::operator()(bool a, int b, int c) {
    return a ? b : c;
}

bool Smaller::operator()(const int &a, const int &b) {
    return a > b;
}

bool IsInRange::operator()(const string &s) {
    return s.size() >= lower && s.size() <= upper;
}

ostream &operator<<(ostream &os, const smallInt &smallInt1) {
    os << smallInt1.val;
    return os;

}