#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> str_idx;
        vector<vector<string>> res;
        int i = 0;
        for(auto s: strs) {
            sort(s.begin(), s.end()); 
            if (str_idx.find(s) == str_idx.end()) {
                res.push_back({strs[i]});
                str_idx[s] = res.size() - 1;
            } else {
                res[str_idx[s]].push_back(strs[i]);
            }
            i += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto strs = vector<string>({"eat","tea","tan","ate","nat","bat"});
    fmt::print("{}\n", sol.groupAnagrams(strs));
}
