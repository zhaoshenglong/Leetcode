#include "../../include/leetcode.hpp"

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, set<int>> steps;
        
        for (auto s: stones)
            steps[s] = set<int>({});
        steps[0].insert(0);

        for (auto s: stones) {
            for (auto step: steps[s]) {
                for (int i = -1; i <= 1; i++) {
                    if (step + i > 0 && steps.find(s + step + i) != steps.end()) {
                        steps[s + step + i].insert(step + i);
                    } 
                }
            }
        }

        return !steps[stones.back()].empty();
    }
};
