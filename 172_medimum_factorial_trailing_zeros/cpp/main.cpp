#include "../../include/leetcode.hpp"

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5)
            return 0;
        int r = n / 5;
        return r + trailingZeroes(r);
    }
};
