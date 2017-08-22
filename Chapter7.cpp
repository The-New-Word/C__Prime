//
// Created by wan on 17-8-19.
//

#include "Sales_data.h"
#include <fstream>

int day7(int argc, char **agrs) {
    fstream input(agrs[1]);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (trans.isbn() == total.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "Wrong!!" << endl;
    }


    return 0;
}