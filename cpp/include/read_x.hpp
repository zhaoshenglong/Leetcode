
#ifndef _READ_X_HPP_
#define _READ_X_HPP_
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> read_vec(const char *filename) {
    fstream fs;
    vector<int> res;
    int num;
    char c;

    fs.open(filename, fstream::in);
    if (!fs.is_open()) {
        cout << "faile open file " << filename << endl;
        return res;
    }
    while (!fs.eof()) {
        if (isdigit(fs.peek())) {
            fs >> num;
            res.push_back(num);
        } else {
            fs.get(c);
        }
    }
    return res;
}
#endif /* _READ_X_HPP_ */
