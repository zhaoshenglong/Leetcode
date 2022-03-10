#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len + 1, 1);
        int i;

        res[len - 1] = nums[len - 1];
        for (i = 1; i < len; i++) {
            res[len - i - 1] = res[len - i] * nums[len - i - 1];
        }

        int prefix = nums[0];
        res[0] = res[1];
        for (i = 1; i < len; i++) {
            res[i] = res[i + 1] * prefix; 
            prefix *= nums[i];
        }

        res.erase(res.end() - 1);
        return res; 
    }
};


