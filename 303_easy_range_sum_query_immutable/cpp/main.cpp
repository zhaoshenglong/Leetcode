#include "../../include/leetcode.hpp"

class NumArray {
public:
    map<int, int> sumTo;

    NumArray(vector<int>& nums) {
        int i = 0;
        int res = 0;
        for (auto n: nums) {
            res += n;
            sumTo[i] = res;
            i++;
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return sumTo[right];
        return sumTo[right] - sumTo[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
