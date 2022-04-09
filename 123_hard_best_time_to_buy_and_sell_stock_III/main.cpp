#include "../include/leetcode.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto n = prices.size();
        auto prev = vector<int>(n);
        auto succ = vector<int>(n);
        auto min_price = vector<int>(n);
        auto max_price = vector<int>(n);
        int i;

        prev[0] = 0;
        min_price[0] = prices[0];
        for (i = 1; i < n; i++) {
            min_price[i] = min(min_price[i - 1], prices[i]);
            prev[i] = max(prev[i - 1], prices[i] - min_price[i]);
        }

        succ[n - 1] = 0;
        max_price[n - 1] = prices[n - 1];
        for (i = n - 2; i >= 0; i--) {
            max_price[i] = max(max_price[i + 1], prices[i]);
            succ[i] = max(succ[i + 1], max_price[i] - prices[i]);
        }

        int res = 0;
        for (i = 0; i < n; i++) {
            res = max(res, prev[i] + succ[i]);
        }
        
        return res;
    }
};
