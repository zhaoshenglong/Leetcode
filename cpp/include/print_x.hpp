#ifndef _PRINT_X_HPP_
#define _PRINT_X_HPP_
#include <iostream>
#include <vector>
#include <set>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
    auto it = s.begin();
    
    os << "[";
    while (it != s.end()) {
        os << *it;
        it++;
        if (it != s.end()) {
            os << ",";
        }
    }
    os << "]" << endl;
    return os;

}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec){
    auto it = vec.begin();
 
    os << "[";
    while (it != vec.end()) {
        os << *it;
        it++;
        if (it != vec.end()) {
            os << ",";
        }
    }
    os << "]" << endl;
    return os;
}

#endif /* _PRINT_X_HPP_ */
