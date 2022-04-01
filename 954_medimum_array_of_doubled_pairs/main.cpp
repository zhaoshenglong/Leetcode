#include "../include/leetcode.hpp"

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, pair<int, int>> numCnt;

        for (auto n :arr) {
            if (n < 0)
                numCnt[-n].second++;
            else
                numCnt[n].first++;
        }
        
        int idx = 0;
        for (auto [n, c]: numCnt) {
            if (numCnt[n * 2].first < numCnt[n].first
                || numCnt[n * 2].second < numCnt[n].second)
                return false;
            numCnt[n * 2].first -= numCnt[n].first;
            numCnt[n * 2].second -= numCnt[n].second;
            idx++;
            if (idx == arr.size() >> 1)
                return true;
        }
        return true;
    }
};
