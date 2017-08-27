//
// Created by wan on 17-8-26.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

void Add(map<string, vector<string>> &family, string &family_name, string &child) {
    family[family_name].push_back(child);
}

void read(istringstream &in) {
    string line;
    getline(cin, line);
    in.str(line);
}

void C11_Test1() {
    int num;
    string buf;
    vector<pair<string, int >> vector1;
    while (cin >> buf >> num) {
        pair<string, int> pair1{buf, num};
        vector1.push_back(pair1);
    }

    for (auto &temp: vector1) {
        cout << temp.first << "   " << temp.second << endl;
    }
}

map<string, string> build_map(ifstream &map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key >> value) {
        if (!value.empty()) {
            trans_map[key] = value;
        }
    }
    return trans_map;

    /*map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);
        } else {
            throw runtime_error("wrong!!");
        }
    }
    return trans_map;
*/
}

const string &transform(const string &s, const map<string, string> &map) {
     auto map_it = map.find(s);
     if (map_it != map.cend()) {
         return map_it->second;
     }

     return s;

}

void word_tramsform(ifstream &map_file, ifstream &input) {
      auto trans_map = build_map(map_file);
      string text;
      while (getline(input, text)) {
          istringstream stream(text);
          string word;
          bool first = true;
          while (stream >> word) {
              if (first) {
                  first = false;
              } else {
                  cout << " ";
              }
              cout << transform(word, trans_map);
          }
          cout << endl;
      }

}

int main() {
    ifstream map_file("map.txt");
    ifstream in("in.txt");
    word_tramsform(map_file, in);


    return 0;
}

void words() {
    map<string, int> word_count;
    istringstream in;
    read(in);
    string word;
    while (in >> word) {
        ++word_count[word];
    }

    for_each(word_count.begin(), word_count.end(), [](pair<string, int> i) {
        cout << i.first << "  " << i.second << endl;
    });
}

void delete_author_books() {
    map<string, vector<string>> author;
    vector<string> books({"aaaa", "bbbb", "cccc"});
    author.insert(make_pair(string("sss"), books));

    auto it = find(author.find("sss")->second.begin(), author.find("sss")->second.end(), "bbbb");
    author.find("sss")->second.erase(it);

    for_each(author.begin(), author.end(), [](pair<string, vector<string>> i) {
        for_each(i.second.begin(), i.second.end(), [](string s) {
            cout << s << endl;
        });
    });
}