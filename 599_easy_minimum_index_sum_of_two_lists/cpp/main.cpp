#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> strPos;
        int i = 0;
        for (auto& s: list1) {
            strPos[s] = i;
            i++;
        }

        int res = INT_MAX;
        unordered_map<int, vector<string>> sumStr;
        i = 0;
        for (auto& s: list2) {
            auto p = strPos.find(s);
            if (p != strPos.end()) {
                res = min(res, p->second + i);
                if (res == p->second + i)
                    sumStr[res].push_back(s);
            }
            i++;
        }
        return sumStr[res];
    }
};
