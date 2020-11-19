#include <iostream>
#include <vector>

using namespace std;


#define JUMP_MAX        100000

class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        int arr[sz];
        int i, j;

        arr[0] = 0;
        for (i = 1; i < sz; i++)
            arr[i] = JUMP_MAX;

        for (i = 0; i < sz; i++) {
            for (j = 1; j <= nums[i] && i + j < sz; j++) {
                if (j + nums[i + j] <= nums[i]) {
                    nums[i + j] = 0;
                    if (i + j == sz - 1 && arr[i + j] > arr[i] + 1)
                        arr[i + j] = arr[i] + 1;
                    continue;
                }
                if (arr[i + j] > arr[i] + 1)
                    arr[i + j] = arr[i] + 1;
            }
        }
        return arr[sz - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    /* int arr[] = {2,3,0,1,4}; */
    /* vector<int> nums(arr, arr + 5); */
    vector<int> nums;
    int i;
    for (i = 0; i < 25000; i++)
        nums.push_back(25000 - i);
    nums.push_back(1);
    nums.push_back(0);
    cout << s.jump(nums) << endl;
    return 0;
}
