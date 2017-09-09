//
// Created by wan on 17-8-27.
//


#include "ch12.h"



shared_ptr<vector<int>> getVector() {

    shared_ptr<vector<int>> p1 = make_shared<vector<int>>(1);
    return p1;


}

shared_ptr<vector<int>> readVector() {
    auto vec = getVector();
    int buf;
    while (cin >> buf) {
        vec->push_back(buf);
    }
    return vec;
}

void C12_Test1() {
    auto vec = readVector();
    sort(vec->rbegin(), vec->rend());
    for_each(vec->begin(), vec->end(), [](int i) {
        cout << i << endl;
    });
}

void C12_Test2() {
    int a = 45;
    shared_ptr<int> p = make_shared<int>(a);
    *p = 44;
    cout << a << endl;
    cout << *p << endl;//注意:如果在智能指针被释放后再度调用被引用的对象会出错!!
}

void C12_Test3() {
    ifstream in("wyx.txt");
    strBlob sb;
    string s;
    while (getline(in, s)) {
        sb.push_back(s);
    }
    for (StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr()) {
        cout << sbp.deref() << endl;
    }
}

int CH12() {
    ifstream in("wyx.txt");
    /* ifstream in("wyx.txt");
     Text_Search text_search(in);
     text_search.search("the");
 */
    TextQuery tq(in);
    while (true) {
        cout << "enter word to look for, or q to quit:";
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }
        print(cout, tq.query(s));
    }
    return 0;
}