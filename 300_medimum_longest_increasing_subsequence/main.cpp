#include "../../include/leetcode.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> incSeq;

        findAllIncSeq(nums, 0, nums.size(), incSeq);
    }

    int findAllIncSeq(vector<int>& nums, int lo, int hi, vector<vector<int>>& seqs) {
        if (lo + 1 == hi) {
            seqs.push_back({nums[lo]});
            return 1;
        }
        vector<vector<int>> leftSeqs, rightSeqs;
        int mid = (lo + hi) >> 1;
        int leftSize = findAllIncSeq(nums, lo, mid, leftSeqs);
        int rightSize = findAllIncSeq(nums, mid, hi, rightSeqs);
         
    }
};

