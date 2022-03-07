#include "../../include/leetcode.hpp"

class Solution {
public:
    string convertToBase7(int num) {
        if (!num)
            return "0";
        bool isNeg = num < 0;
        string res(10, 0);
        if (isNeg) {
            num = -num;
        }
        int i = 9;
        while(num > 0) {
            res[i] = '0' + num % 7;
            num /= 7;
            i--;
        }
        if (isNeg)
            return "-" + res.substr(i + 1);
        return res.substr(i + 1);
    }
};

