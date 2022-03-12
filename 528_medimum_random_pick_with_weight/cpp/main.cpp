#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        int sum = 0;
        for (auto n: w) {
            sum += n;
            prefix.push_back(sum);
        }
    }

    int pickIndex() {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<std::mt19937::result_type> dist(0, prefix.back());

        int weight = dist(dev);
        return binary_search(prefix, weight);
    }

    int binary_search(vector<int>& vec, int target) {
        int lo = 0, hi = vec.size();
        int mid;

        while(lo < hi) {
            mid = (lo + hi) >> 1;
            if (vec[mid] == target)
                return mid;
            if (vec[mid] > target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
