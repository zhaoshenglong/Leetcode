#ifndef _PRINT_X_HPP_
#define _PRINT_X_HPP_
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec){
    auto it = vec.begin();
 
    os << "[";
    for(; it != vec.end() && it + 1 != vec.end(); it++)
        os << *it << ", ";
    if (it != vec.end())
        os << *it;
    os << "]";
    return os;
}

#endif /* _PRINT_X_HPP_ */
