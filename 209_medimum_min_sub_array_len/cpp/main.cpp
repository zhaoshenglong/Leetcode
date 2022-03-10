#include "../../include/leetcode.hpp"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;

        int sum = 0;
        int lo = 0;
        int i;
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(sum >= target && lo <= i) {
                res = min(res, i - lo + 1);
                sum -= nums[lo];
                lo++;
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }

    int minSubArrayLenBinary(int target, vector<int>& nums) {
        int res = minSubArrayLenDivide(target, nums, 0, nums.size());
        if (res == INT_MAX)
            return 0;
        return res;
    }

    int minSubArrayLenDivide(int target, vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            if (nums[lo] >= target)
                return 1;
            return INT_MAX;
        }
        int mid = (lo + hi) >> 1;
        int left = minSubArrayLenDivide(target, nums, lo, mid);
        int right = minSubArrayLenDivide(target, nums, mid + 1, hi);
        int res = INT_MAX;
        int sum = nums[mid] + nums[mid + 1];
        int i = mid - 1, j = mid + 2;
        while (i >= lo && j <= hi) {
            if (sum >= target) {
                res = j - i + 1;
                break;
            }
            if (nums[i] > nums[j]) {
                sum += nums[i];
                i--;
            } else {
                sum += nums[j];
                j++;
            }
        }
        while (i >= lo) {
            sum += nums[i];
            i--;
            if (sum >= target) {
                res = j - i + 1;
                break;
            }
        }
        while (j <= hi) {
            sum += nums[j];
            j++;
            if (sum >= target) {
                res = j - i + 1;
                break;
            }
        }
        return min({res, left, right});
    }
};


