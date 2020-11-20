#include <iostream>
#include <vector>
#include <set>
#include "../include/print_x.hpp"

using namespace std;

#define swap(a, b)          \
    do {                    \
        a ^= b;             \
        b ^= a;             \
        a ^= b;             \
    } while(0)

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUniqueBt(nums, 0, nums.size(), res);
        return res;
    }

    void permuteUniqueBt(vector<int>& nums, int lo, int hi, vector<vector<int>>& res) {
        int i;
        set<int> accessed;

        if (hi == lo + 1) {
            res.push_back(vector<int>(nums));
        } else {
            permuteUniqueBt(nums, lo + 1, hi, res);
            accessed.insert(nums[lo]);
            for (i = lo + 1; i < hi; i++) {
                if (accessed.find(nums[i]) == accessed.end()) {
                    accessed.insert(nums[i]);
                    swap(nums[i], nums[lo]);
                    permuteUniqueBt(nums, lo + 1, hi, res);
                    swap(nums[i], nums[lo]);
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int arr[] = {1, 1, 2};
    vector<int> nums(arr, arr + 3);

    cout << s.permuteUnique(nums);
    return 0;
}
