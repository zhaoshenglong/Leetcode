#include "../../include/leetcode.hpp"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> prefix;
        int sum = 0;
        int i;

        prefix[0] = -1;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)            
                sum += -1;
            else
                sum += 1;
            if (prefix.find(sum) != prefix.end()) {
                if (i - prefix[sum] > res)
                    res = i - prefix[sum];
            } else {
                prefix[sum] = i;
            }
        }

        return res;
    }
};


