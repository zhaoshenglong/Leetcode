#include "../../include/leetcode.hpp"

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int mask = 0x1;
        if ((n & 1) == 0)
            mask = 0x2;
        while(n > 0) {
            if ((n & mask) != mask)
                return false;
            n >>= 2;
        }
        return true;
    }
};
