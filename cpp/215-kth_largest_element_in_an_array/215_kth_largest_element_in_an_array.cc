#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define swap(nums, i, j)        \
    do {                        \
        int t = nums[i];        \
        nums[i] = nums[j];      \
        nums[j] = t;            \
    } while(0)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size();

/*         if (sz < 43) { */
/*             sort(nums.begin(), nums.end()); */
/*             return nums[sz - k]; */
/*         } */
        
        return random_select(nums, sz - k, 0, sz - 1);
    }
    /**
     * random select algorithm
     * The process is like that in quicksort, 
     * but drop half of the array in each iteration.
     */
    int random_select(vector<int>& nums, int k, int lo, int hi) {
        int i;
        
        if (hi <= lo)
            return nums[lo];
        
        i = this->random_partition(nums, lo, hi);
        if (i == k)
            return nums[i];
        else if (i > k)
            return random_select(nums, k, lo, i);
        else
            return random_select(nums, k, i + 1, hi);
    }

    int random_partition(vector<int>& nums, int lo, int hi) {
        int i = lo + 1;
        int j = lo;
        int val = nums[lo];

        for (; i <= hi; i++) {
            if (nums[i] < val) {
                j++;
                if (j != i)
                    swap(nums, i, j);
            }
        }
        swap(nums, j, lo);
        return j;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    cout << s.findKthLargest(nums, k) << endl;
    return 0;
}
