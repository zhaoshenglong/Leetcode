#include <iostream>
#include <vector>
#include "../include/print_x.hpp"

using namespace std;
#define swap(a, b)          \
    do{                     \
        int t = a;          \
        a = b;              \
        b = t;              \
    } while(0)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        bool flipped = true;
        int sz = nums.size();

        for (i = sz - 2; i >= 0; i--) {
            if (flipped) {
                if (nums[i] >= nums[sz - 1]) {
                    for (j = i; j < sz - 1; j++)
                        swap(nums[j], nums[j + 1]);
                } else {
                    flipped = false;
                    for (j = i + 1; j <= sz - 1; j++) {
                        if (nums[j] > nums[i]) {
                            swap(nums[i], nums[j]);
                            return;
                        }
                    }
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int arr[] = {1, 1, 5};
    vector<int> nums(arr, arr + 3);

    s.nextPermutation(nums);
    cout << nums << endl;
    return 0;
}
