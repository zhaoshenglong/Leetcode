#include "../../include/leetcode.hpp"

class Solution {
public:
    int addDigits(int num) {
        if (num < 10)
            return num;
        int i, res = 0;
        for(i = 0; i < 10; i++) {
            res += (num % 10);
            num /= 10;
            if (num == 0)
                break;
        } 
        return addDigits(res);
    }
};

int main() {
    Solution sol;
    int num = 2147483647;
    cout << sol.addDigits(num);
}