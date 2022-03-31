#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        int i;

        res.resize(right - left + 1);
        for (i = left; i < right; i++) {
            if (isSelfDividing(i))
                res[i - left] = i;
        }
        return res;
    }

    bool isSelfDividing(int num) {
        int n = num;
        while(n > 0) {
            if (num % (n % 10) != 0)
                return false;
            n /= 10;
        }
        return true;
    }
};
