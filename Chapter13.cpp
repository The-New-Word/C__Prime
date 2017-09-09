//
// Created by wan on 17-8-30.
//


#include "Chapter13.h"


int ch13() {
    Sales_data sales_data;
    cin >> sales_data;
    cout << sales_data;

    return 0;
}

int Employee::basic_num = 1;

Employee::Employee() {
    num = basic_num++;
}

Employee::Employee(const string &name) {
    this->name = name;
    this->num = basic_num++;
}

HasPtr1::~HasPtr1() {
    --*use;//先对引用计数进行递减操作
    if (*use == 0) {
        delete ps;
        delete use;
    }

}

HasPtr1 &HasPtr1::operator=(const HasPtr1 &ptr1) {
    ++*ptr1.use;//递增右侧引用计数
    --*this->use;//递减左侧的引用技术
    if (*this->use == 0) {//如果左侧的引用计数为0则删除内存空间
        delete this->ps;
        delete this->use;
    }
    //将右侧的值赋予左侧
    this->ps = ptr1.ps;
    this->use = ptr1.use;
    this->i = ptr1.i;
    return *this;

}

TreeNode::~TreeNode() {
    --*count;
    if (*count == 0) {
        delete count;
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }

    }
}

TreeNode &TreeNode::operator=(const TreeNode &treeNode) {
    --*this->count;
    ++*treeNode.count;
    if (*this->count == 0) {
        delete this->count;
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }
    }
    this->count = treeNode.count;
    this->right = treeNode.right;
    this->left = treeNode.left;
    return *this;
}

BinStrTree &BinStrTree::operator=(const BinStrTree &binStrTree) {
    auto newNode = new TreeNode(*binStrTree.root);//如果不使用new重新分配内存空间,会导致两个指针指向同一片内存区域
    delete root;
    root = newNode;
    return *this;
}

inline void swap(HasPtr &h1, HasPtr &h2) {
    //交换两者的指针
    using std::swap;
    swap(h1.ps, h2.ps);
    cout << "交换" << endl;
    swap(h1.i, h2.i);
}


inline void swap(Foo &f1, Foo &f2) {

    swap(f1.hasPtr, f2.hasPtr);
}

inline bool operator<(HasPtr &p1, HasPtr &p2) {
    return *p1.ps < *p2.ps;
}

void Message::save(Folder &f) {
    //先将要存放的folder保存
    //再将当前的message保存到folder中
    this->folders.insert(&f);//因为使用的是指针类型,所以必须传递一个指针变量
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    this->folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folder(const Message &msg) {
    //将本Message保存到指向msg的Folder中
    for (auto f:msg.folders) {//遍历每一个包含msg的Folder,然后将当前message添加到Folder中
        f->addMsg(this);
    }

}

Message::Message(const Message &msg) : contents(msg.contents), folders(msg.folders) {
    add_to_folder(msg);
}

void Message::re_from_folder() {
    for (auto f: folders) {//遍历每一个保存当前message的folder,从中删除本message
        f->remMsg(this);
    }
}

Message::~Message() {
    re_from_folder();
}

Message &Message::operator=(const Message &msg) {
    re_from_folder();//先从每一个folder中删除当前msg
    this->folders = msg.folders;
    this->contents = msg.contents;
    add_to_folder(msg);//再将当前Message添加到msg的每一个folder中
    return *this;
}

inline void swap(Message &m1, Message &m2) {
    //先将包含m1与m2的folder里的m1与m2删除
    for (auto f: m1.folders) {
        f->remMsg(&m1);
    }
    for (auto f: m2.folders) {
        f->remMsg(&m2);
    }
    using std::swap;
    swap(m1.folders, m2.folders);
    swap(m1.contents, m2.contents);
    for (auto f: m1.folders) {
        f->addMsg(&m1);
    }
    for (auto f: m2.folders) {
        f->addMsg(&m2);
    }
}

void Message::addfol(Folder *f) {
    f->messages.insert(this);
    folders.insert(f);

}

void Message::move_Folders(Message *msg) {
    folders = move(msg->folders);
    for (auto f: folders) {
        f->remMsg(msg);
        f->addMsg(this);
    }
    msg->folders.clear();
}

void Folder::addMsg(Message *msg) {
    this->messages.insert(msg);
    msg->folders.insert(this);
}

void Folder::remMsg(Message *msg) {
    this->messages.erase(msg);

}

Folder::Folder(const Folder &f) : messages(f.messages) {
    add_to_msg(&f);

}

void Folder::remove_from_msg() {
    for (auto msg: messages) {
        msg->remove(*this);
    }
}

Folder::~Folder() {
    remove_from_msg();
}

void Folder::add_to_msg(const Folder *folder) {
    for (auto m: folder->messages) {
        m->save(*this);
    }
}

Folder &Folder::operator=(const Folder &f) {
    remove_from_msg();
    this->messages = f.messages;
    add_to_msg(&f);
    return *this;

}

void Folder::print() {
    for (auto msg:messages) {
        cout << msg->contents << endl;
    }

}
