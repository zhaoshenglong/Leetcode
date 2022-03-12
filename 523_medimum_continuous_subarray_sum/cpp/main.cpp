#include "../../include/leetcode.hpp"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> modulos;
        int len = nums.size();
        int sum = 0;
        int i;

        modulos[0] = 0;
        for (i = 0; i < len; i++) {
            sum += nums[i];
            sum %= k;
            if (modulos.find(sum) != modulos.end()) {
                if (i - modulos[sum] >= 2)
                    return true;
            } else {
                modulos[sum] = i;
            }
        }
        fmt::print("{}\n", modulos);
        return false;
    }
};
int main() {
    Solution sol;
    auto nums = vector<int>({23,2,6,4,7});
    int k = 6;
    cout << sol.checkSubarraySum(nums, k) << endl;
}
