#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        map<int, int> plateCnt;
        vector<tuple<int, int>> platePos(s.size(), {0,0});
        int cnt = 1;
        int i, j;

        int lastPlatePos = -1;
        for(i = 0; i < (int)s.size(); i++) {
            if (s[i] == '|') {
                plateCnt[i] = cnt;
                cnt++;
                for (j = lastPlatePos + 1; j < i; j++) {
                    platePos[j] = make_tuple(lastPlatePos, i);
                }
                platePos[i] = make_tuple(i, i);
                lastPlatePos = i;
            }
        }
        for (j = lastPlatePos + 1; j < i; j++) {
            platePos[j] = make_tuple(lastPlatePos, -1);
        }
        
        vector<int> res;
        int leftmost, rightmost;
        for (auto &query : queries) {
            leftmost = get<1>(platePos[query[0]]);
            if (leftmost == -1) {
                res.push_back(0);
                continue;
            }
            rightmost = get<0>(platePos[query[1]]);
            if (leftmost == rightmost || leftmost + 1 == rightmost) {
                res.push_back(0);
                continue;
            }
            res.push_back(rightmost - leftmost - 1 - (plateCnt[rightmost] - plateCnt[leftmost] - 1));
        }
        return res;
    }
};


