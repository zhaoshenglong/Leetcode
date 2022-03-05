#include "../../include/leetcode.hpp"

class Solution {
    int magic = 1337;
public:
    int superPow(int a, vector<int>& b) {
        int lo = 0;
        return powRecursive(a, b, lo);
    }

    int powRecursive(int a, vector<int>& b, int& lo) {
        if (lo == b.size() - 1 && b[lo] == 1)
            return a % magic;
        int base = 1;
        if (!isEven(b))
            base = a % magic;
        rightShiftOneBit(b, lo);
        int halfPow = powRecursive(a, b, lo);
        return (((halfPow * halfPow) % magic) * base) % magic;
    }

    bool isEven(vector<int>& b) {
        return !(b[b.size() - 1] & 1);
    }

    void rightShiftOneBit(vector<int>& b, int& lo) {
        int odd;
        int i;
        for (i = lo; i < b.size() - 1; i++) {
            odd = b[i] & 1;
            b[i] >>= 1;
            b[i + 1] += 10 * odd;
        }
        b[b.size() - 1] >>= 1;
        if (b[lo] == 0)
            lo++;
    }
};
