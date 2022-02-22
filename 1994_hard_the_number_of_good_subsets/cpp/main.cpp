#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fmt/ranges.h>

using namespace std;

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        auto numFreq = countFreq(nums);
        auto allGoodSubsets = goodSubsets();
        
        return 0;
    }

    // count occurrences of all the numbers
    map<int, int> countFreq(vector<int> &nums) {
        auto res = map<int, int>();
        for (auto i : nums) {
            res[i] += 1;
        }
        return res;
    }

    // Find all of the good subsets in 1..30
    vector<set<int>> goodSubsets() {
        auto goodNums = vector<int>({2, 3, 5});
        //auto goodNums = vector<int>({2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 
        //                 17, 19, 21, 22, 23, 26, 29, 30});
        auto factorSetMap = map<int, set<int>>({
                {2, {2}}, {3, {3}}, {5, {5}}, {6, {2, 3}},
                {7, {7}}, {10, {2, 5}}, {11, {11}}, {13, {13}},
                {14, {2, 7}}, {15, {3, 5}}, {17, {17}}, 
                {19, {19}}, {21, {3, 7}}, {23, {23}},
                {26, {2, 13}}, {29, {29}}, {30, {2, 3, 5}}});

        // generate good subsets
        return goodSubsetsRecursive(goodNums, factorSetMap, 0, goodNums.size());
    }
    
    vector<set<int>> goodSubsetsRecursive(vector<int> &nums, map<int, set<int>> &factors, int lo, int hi) {
        if (lo == hi - 1) {
            return vector<set<int>>({{nums[lo]}});
        }else {
            vector<set<int>> res;
            res.push_back({{nums[lo]}});
            vector<set<int>> r = goodSubsetsRecursive(nums, factors, lo + 1, hi);
            fmt::print("{}\n", r);
            res.insert(res.end(), r.begin(), r.end());
            for (auto s: r) {
                bool insertValid = true;
                for (auto i : s) {
                    if (hasCommonFactor(nums[lo], i, factors)) {
                        insertValid = false;
                        break;
                    }
                }
                if (insertValid)
                    s.insert(nums[lo]);
            }
            res.insert(res.end(), r.begin(), r.end());
            return res;
        }
    }
    
    bool hasCommonFactor(int a, int b, map<int, set<int>> &factors) {
        for(auto i : factors[a]) {
            for (auto j: factors[b]) {
                if (i == j)
                    return true;
            }
        } 
        return false;
    }
};

int main() {
    //auto solution = Solution();
    //vector<int> nums({1,2,3,4,5});
    vector<set<int>> nums{{1,2}, {2, 3}};
    fmt::print("{}\n", nums);
    return 0;
}
