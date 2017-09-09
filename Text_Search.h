//
// Created by wan on 17-8-31.
//

#ifndef C_PRIME_TEXT_SEARCH_H
#define C_PRIME_TEXT_SEARCH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include <utility>

using namespace std;


class Text_Search {
public:
    Text_Search() = default;

    explicit Text_Search(ifstream &);

    void read(ifstream &);

    void search(const string &);

private:
    vector<string> line;//对应文件中的一行文本
    map<string, set<int>> words_num;//一个单词对应一个行号
    void split_line(const string &, int &);
};

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;

    explicit TextQuery(ifstream &);

    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file;//输入文件
    map<string, shared_ptr<set<line_no >>> wm;
};

class QueryResult {
    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) :
            sought(s), lines(p), file(f) {}

private:
    string sought;
    shared_ptr<set<TextQuery::line_no >> lines;
    shared_ptr<vector<string>> file;

};

#endif //C_PRIME_TEXT_SEARCH_H
