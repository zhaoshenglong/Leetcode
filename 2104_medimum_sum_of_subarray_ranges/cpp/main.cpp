#include "../../include/leetcode.hpp"

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        map<int, tuple<int,int>> subarray_min_max;
        int len = nums.size();
        int i, j;

        if (len == 1)
            return 0;
        
        sumDiffRecursive(nums, 0, len  - 1, res); 
        return res;
    }

    void sumDiffRecursive(vector<int>& nums, int lo, int hi, long long &res) {
        if (lo == hi)
            return;
        if (lo + 1 == hi) {
            res += abs(nums[lo] - nums[hi]);
            return;
        }
        int mid = (lo + hi) >> 1;
        sumDiffRecursive(nums, lo, mid, res);
        sumDiffRecursive(nums, mid + 1, hi, res);
        int i = mid, j = mid + 1;
        int min_num, max_num;
        int lmin = nums[mid], lmax = nums[mid];
        for (i = mid; i >= lo; i--)  {
            min_num = lmin = min(lmin, nums[i]);
            max_num = lmax = max(lmax, nums[i]);
            for (j = mid + 1; j <= hi; j++) {
                min_num = min(min_num, nums[j]);
                max_num = max(max_num, nums[j]);
                res += max_num - min_num;
            }
        }
    }
};

int main() {
    Solution sol;
    auto nums = vector<int>({4, -2, -3, 4, 1});
    cout << sol.subArrayRanges(nums) << endl;
    return 0;
}