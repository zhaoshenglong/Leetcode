#include <iostream>
#include <vector>
#include "../include/print_x.hpp"

using namespace std;

#define swap(a, b)          \
    do{                     \
        int t = a;          \
        a = b;              \
        b = t;              \
    } while(0)              \

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute_bt(nums, 0, nums.size(), res);
        return res;
    }
    
    void permute_bt(vector<int> &nums, int lo, int hi, vector<vector<int>> &res) {
        int i;

        if (hi == lo + 1) {
            res.push_back(vector<int>(nums));
        } else {
            for (i = lo; i < hi; i++) {
                swap(nums[lo], nums[i]);
                permute_bt(nums, lo + 1, hi, res);
                swap(nums[lo], nums[i]);
            }        
        }
    }
    
};

int main(int argc, char *argv[]) {
    Solution s;
    int arr[] = {1, 2, 3};
    vector<int> nums(arr, arr + 3);
    cout << s.permute(nums) << endl;;    
    return 0;
}
