#include "../../include/leetcode.hpp"

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = maxBitwiseOr(nums);
        int res = 0;
        vector<int> subsetList;
        countSubsetsEqual(nums, 0, maxOr, subsetList);
        for (auto n: subsetList) {
            if (n == maxOr)
                res++;
        }
        return res;
    }

    int maxBitwiseOr(vector<int>& nums) {
        int res = 0;
        for (auto n: nums)
            res |= n;
        return res;
    }

    void countSubsetsEqual(vector<int>& nums, int lo, int target, vector<int>& subsetList) {
        vector<int> subsets;
        for(auto& s: subsetList) {
            subsets.push_back(s | nums[lo]);
        }
        subsetList.insert(subsetList.end(), subsets.begin(), subsets.end());
        subsetList.push_back({nums[lo]});
        fmt::print("{}\n", subsetList);
        if (lo == nums.size() - 1)
            return;
        countSubsetsEqual(nums, lo + 1, target, subsetList);
    }
};

int main() {
    Solution sol;
    auto nums = vector<int>({3,2,1,5});
    cout << sol.countMaxOrSubsets(nums) << endl;
}
