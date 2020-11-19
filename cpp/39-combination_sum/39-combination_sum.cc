#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "../include/print_x.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res_set;
        int sz = candidates.size();
        int i;
        
        for (i = 0; i < sz; i++) {
            if (candidates[i] < target) {
                for (auto v : combinationSum(candidates, target - candidates[i])) {
                    v.push_back(candidates[i]);
                    sort(v.begin(), v.end());
                    res_set.insert(v);
                }
            } else if (candidates[i] == target) {
                res_set.insert(vector<int>(1, target));
            }
        }

        return vector<vector<int>>(res_set.begin(), res_set.end());
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int arr[] = {2,3,6,7};
    vector<int> cands(arr, arr + 4);

    cout << s.combinationSum(cands, 7) << endl;
    return 0;
}
