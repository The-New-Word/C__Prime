//
// Created by wan on 17-8-31.
//

#ifndef C_PRIME_CHAPTER13_H
#define C_PRIME_CHAPTER13_H

#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include "StrVec.h"
#include "Sales_data.h"
using namespace std;
//注:
// 1.析构函数按照成员初始化的逆序进行销毁
// 2.如果一个类需要自定义析构函数时必定需要拷贝构造函数与拷贝赋值运算符;当一个类的成员需要动态分配内存且未delete掉,就必定要自定义析构函数,在析构函数中delete
// 3.拷贝构造函数的任务是拷贝元素的值,对于指针就需要重新new;拷贝赋值运算符的任务是
// 4.拷贝赋值运算符一般包含析构部分和拷贝部分,先析构再拷贝,但要注意在析构之前需要先保存右侧对象,以防出现自赋值
// 5.行为像值的类:多个该类对象互不影响.(类似于string这类)
// 6.行为像指针的类:如果用一个对象去赋值给另一个对象,两者会相互影响.(类似于智能指针)
// 7.移动构造函数从对象中窃取资源,然后将源对象置空

class Point {
public:
    Point() = default;

    explicit Point(int i) : id(i) {}

    Point(Point &p) {
        id = p.id;
        cout << "拷贝:  " << id << endl;
    }

private:
    int id;

};

Point global(1);

Point foo_bar(Point arg) {
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = {local, *heap};
    return *heap;
}

class HasPtr {//类值行为的类,就是指通过赋值操作,两个类的值一样,但指向的内存空间是完全不同的!!
public:
    explicit HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

    friend void swap(HasPtr &, HasPtr &);

    friend bool operator<(HasPtr &, HasPtr &);

    HasPtr(HasPtr &&has)noexcept: ps(has.ps), i(has.i) { has.ps = nullptr; }

    HasPtr(const HasPtr &ptr) : ps(new string(*ptr.ps)), i(ptr.i) {}//new string(*ptr.ps)重新开辟一片内存空间并用*ptr.ps的值进行初始化
    //
/*
    HasPtr &operator=(HasPtr &&p) {//移动赋值运算符
        if (this != &p) {//自赋值检测
            delete ps;
            ps = p.ps;
            i = p.i;
            p.ps = nullptr;
        }
        return *this;
    }*/
    HasPtr &operator=(const HasPtr &p) {//拷贝赋值运算符
        auto new_p = new string(*p.ps);// 注:先定义一个局部变量保存右侧对象，如果右侧对象和左侧对象是同一个对象，那么先删除右侧对象就会发生错误
        delete ps;
        ps = new_p;
        i = p.i;
        return *this;

    }

    /* HasPtr &operator=(HasPtr p) {
         //拷贝并交换技术
         swap(*this, p);
         return *this;
     }
 */

    ~HasPtr() {
        delete ps;
    }

private:
    string *ps;
    int i;
};

class Foo {
public:
    friend void swap(Foo &, Foo &);


private:
    HasPtr hasPtr;
};

struct X {
    X() {
        cout << "X:" << endl;
    }

    X(const X &x) {
        cout << "X(const X &x)" << endl;
    }

    ~X() {
        cout << "~X()" << endl;
    }

    X &operator=(const X &x) {
        cout << "X &operator=(const X&x)" << endl;
        return *this;
    }
};

class num {
public:
    num() {
        mys = rand() % 100;
    }

    num(const num &n) {
        mys = rand() % 100;
    }

    int get() {
        return mys;
    }


private:
    int mys;
};

void f(num &n) {
    cout << n.get() << endl;
}

class NoCopy {
public:
    NoCopy() = default;

    NoCopy(const NoCopy &no) = delete;

    NoCopy &operator=(const NoCopy &no) = delete;
};

class Employee {
public:
    Employee();

    explicit Employee(const string &);

private:
    string name;
    int num;
    static int basic_num;
};

class HasPtr1 {//类指针行为的类,通过赋值操作,两个类指向同一片内存空间,对一个的操作会影响到另一个
public:
    explicit HasPtr1(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr1(const HasPtr1 &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }//直接用指针进行赋值

    HasPtr1 &operator=(const HasPtr1 &);

    ~HasPtr1();

private:
    string *ps;
    int i;
    size_t *use;
};

class TreeNode {
public:
    TreeNode() : value(""), count(new int(1)), left(nullptr), right(nullptr) {}

    TreeNode(const TreeNode &treeNode) : value(treeNode.value), count(treeNode.count), left(treeNode.left),
                                         right(treeNode.right) { ++*count; }

    TreeNode &operator=(const TreeNode &treeNode);

    ~TreeNode();

private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) {}

    BinStrTree(const BinStrTree &binStrTree) : root(new TreeNode(*binStrTree.root)) {};

    ~BinStrTree() {
        delete root;
    }

    BinStrTree &operator=(const BinStrTree &binStrTree);

private:
    TreeNode *root;

};

class Folder;

class Message {
    friend class Folder;


    friend void swap(Message &, Message &);

public:
    explicit Message(string str = "") : contents(std::move(str)) {}

    Message(const Message &);

    Message &operator=(const Message &);

    void move_Folders(Message *);

    Message &operator=(Message &&msg) {

        if (this != &msg) {//检测自赋值情况
            re_from_folder();//先删除当前msg中的folder,必须先删除左侧运算对象的旧的状态
            contents = move(msg.contents);//将msg的contents移动到当前msg
            move_Folders(&msg);//移动folders
        }
        return *this;
    }

    Message(Message &&msg) : contents(move(msg.contents)) {
        move_Folders(&msg);
    }

    ~Message();

    void save(Folder &);

    void remove(Folder &);

    void addfol(Folder *);

private:
    string contents;//Message包含的实际文本
    set<Folder *> folders;//包含Message的Folder
    void add_to_folder(const Message &);//将本Message添加到指向参数的的Folder中

    void re_from_folder();//从每一个folder中删除本Message
};

class Folder {
    friend class Message;

    friend void swap(Message &, Message &);

public:
    Folder() = default;

    Folder(const Folder &);

    Folder &operator=(const Folder &);

    ~Folder();

    void print();

private:
    void addMsg(Message *);

    void remMsg(Message *);

    void remove_from_msg();

    void add_to_msg(const Folder *);

    set<Message *> messages;
};


#endif //C_PRIME_CHAPTER13_H
