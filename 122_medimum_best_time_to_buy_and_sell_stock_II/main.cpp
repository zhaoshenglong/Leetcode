#include "../include/leetcode.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 1, p;
        
        while(i < prices.size()) {
            p = i;
            while(i + 1 < prices.size() && prices[i + 1] >= prices[i])
                i++;
            profit += prices[i] - prices[p];
            i++;
        }

        return profit;
    }
};
