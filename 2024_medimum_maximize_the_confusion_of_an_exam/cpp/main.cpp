#include "../../include/leetcode.hpp"

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int> trues, falses; 
        int i;
        
        for (i = 0; i < answerKey.size(); i++) {
            if (answerKey[i] == 'T')
                trues.push_back(i);
            else
                falses.push_back(i);
        }
        if (k >= trues.size() || k >= falses.size())
            return answerKey.size();

        if (answerKey.back() == 'T')
            falses.push_back(answerKey.size());
        else
            trues.push_back(answerKey.size());

        return max(maxTFAnswers(trues, k), maxTFAnswers(falses, k));
    }

    int maxTFAnswers(vector<int>& pos, int k) {
        int i = k;
        int p = 0;
        int res = 0; 
        while(i < pos.size()) {
            if(pos[i] - p > res)
                res = pos[i] - p;
            p = pos[i - k] + 1;
            i++;
        }
        return res;
    }
};

