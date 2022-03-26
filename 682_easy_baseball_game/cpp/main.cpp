#include "../../include/leetcode.hpp"

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (auto &op : ops) {
            if (op.size() == 1) {
                if (op[0] == 'C') {
                    scores.pop_back();
                    continue;
                }
                if (op[0] == 'D') {
                    scores.push_back(scores[scores.size() - 1] * scores[scores.size() - 2]);
                    continue;
                }
                if (op[0] == '+') {
                    scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
                    continue;
                }
            }
            scores.push_back(atoi(op.data()));
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
