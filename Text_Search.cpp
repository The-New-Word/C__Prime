//
// Created by wan on 17-8-31.
//

#include "Text_Search.h"


void Text_Search::read(ifstream &in) {
    string buf;
    int line = 0;
    while (getline(in, buf)) {
        line++;
        this->line.push_back(buf);
        split_line(buf, line);
    }
}

void Text_Search::split_line(const string &line, int &num) {
    istringstream in(line);
    string buf;
    while (in >> buf) {
        words_num[buf].insert(num);
    }
}

void Text_Search::search(const string &key) {
    auto it = words_num.find(key);
    auto begin = it->second.begin();
    while (begin != it->second.end()) {
        int line_num = (*begin) - 1;//行号
        string line_str = line[line_num];
        cout << "line " << line_num << ": " << line_str << endl;
        begin++;
    }

}

Text_Search::Text_Search(ifstream &in) {
    read(in);
}

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        auto n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }

    }

}

QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no >> nodata(new set<line_no>);//如果未找到,返回词指针
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);//未找到
    } else {
        return QueryResult(sought, loc->second, file);
    }

}

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << "occursa" << qr.lines->size() << " "
       << (qr.lines->size() > 1 ? "times" : "time") << endl;
    for (auto temp: *qr.lines) {
        os << "\t(line" << temp + 1 << ")" << *(qr.file->begin() + temp) << endl;
    }
    return os;
}
