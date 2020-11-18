#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i;
        int sz = nums.size();
        int abs_n;

        for (i = 0; i < sz; i++) {
            if (nums[i] <= 0)
                nums[i] = sz + 1;
        }

        for (i = 0; i < sz; i++) {
            abs_n = nums[i] < 0 ? -nums[i] : nums[i];

            if ( abs_n <= sz && nums[abs_n - 1] > 0)
                nums[abs_n - 1] = -nums[abs_n - 1];
        }

        for (i = 0; i < sz; i++)
            if (nums[i] > 0)
                return i + 1;
        return i + 1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int arr[] = {3,4,-1,1};
    vector<int> nums(arr, arr + 4);

    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}
