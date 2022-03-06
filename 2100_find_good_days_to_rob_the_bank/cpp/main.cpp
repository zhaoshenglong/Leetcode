#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int len = security.size();
        vector<int> goodDays(len, 0);
        int dec = 0, inc = 0;
        vector<int> res;
        int i;

        if (len <= time << 1)
            return {};
        if (time == 0) {
            for (i = 0; i < len; i++)
                res.push_back(i);
            return res;
        }

        for (i = 1; i < len; i++) {
            if (security[i] <= security[i - 1])
                dec++;
            else
                dec = 0;
            if (security[len - i - 1] <= security[len - i])
                inc++;
            else
                inc = 0;
            if (dec >= time)
                goodDays[i]++;
            if (inc >= time)
                goodDays[len - i - 1]++;
        }
        
        for (i = time; i < len - time; i++) {
            if (goodDays[i] == 2)
                res.push_back(i);
        }
        return res;
    }

};
int main() {
    Solution sol;
    auto security = vector<int>({1,2,3,4,5,6,321,434,431,55,66,431,3444});
    auto time = 2;
    fmt::print("{}\n", sol.goodDaysToRobBank(security, time));
    return 0;
}
