#include "../../include/leetcode.hpp"

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int lo  = nums[0];
        int res = -1;
        int i, val;
        for (i = 1; i < nums.size(); i++) {
            val = nums[i];
            if (val < lo) {
                lo = val;
            } else {
                if (val - lo > res)
                    res = val - lo;
            }
        }
        return res;
    }
};

