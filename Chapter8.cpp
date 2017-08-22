//
// Created by wan on 17-8-21.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;
struct peoples {
    string name;
    vector<string> phones;
};

void readLine(const string &file, vector<string> &vector1);

istream &read(istream &is);

int day8() {
    string line, word;
    vector<peoples> people;
    while (getline(cin, line)) {
        peoples people1;
        istringstream record(line);
        record >> people1.name;
        while (record >> word) {
            people1.phones.push_back(word);

        }
        people.push_back(people1);

    }
    return 0;
}

istream &read(istream &is) {
    string buf;
    while (is >> buf) {
        cout << buf << endl;
    }
    is.clear();
    return is;
}

void readLine(const string &file, vector<string> &vector1) {
    ifstream read(file);//用传进来的file构建一个读取流

    cout << file << endl;
    if (read) {
        cout << "start read" << endl;
        string buf;//预读取
        while (read >> buf) {
            vector1.push_back(buf);
            buf.clear();
        }
    } else {
        cout << read.rdstate() << endl;
        cout << "It's err!" << endl;
        read.close();
        return;
    }
    read.close();
    cout << "read success!" << endl;


}