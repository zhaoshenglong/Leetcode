#include "../../include/leetcode.hpp"

class Solution {
public:
    int getSum(int a, int b) {
        unsigned res = a ^ b;
        unsigned carry = a & b;
        if (carry == 0)
            return res;
        return getSum(res, carry << 1);
    }
};

int main() {
    Solution sol;
    cout << sol.getSum(3, 7) << endl;
}