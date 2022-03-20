#include "../../include/leetcode.hpp"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if (m < n)
            return addStrings(num2, num1);

        int carry = 0;
        int i;
        for (i = 0; i < n; i++) {
            num1[m - i - 1] += num2[n - i - 1] - 48 + carry;
            if (num1[m - i - 1] > '9') {
                carry = 1;
                num1[m - i - 1] -= 10;
            } else {
                carry = 0;
            }
        }
        for (i = n; i < m; i++) {
            num1[m - i - 1] += carry;
            if (num1[m - i - 1] > '9') {
                carry = 1;
                num1[m - i - 1] -= 10;
                continue;
            } else {
                carry = 0;
                return num1;
            }
        }
        if (carry)
            return "1" + num1;
        return num1;
    }
};

