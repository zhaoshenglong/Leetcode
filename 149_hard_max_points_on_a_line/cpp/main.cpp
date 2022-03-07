#include "../../include/leetcode.hpp"

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        vector<vector<int>> sameLineCnt;
        int res = 0;
        int i, j,k;

        if (len == 1)
            return 1;
        init(sameLineCnt, len);
        for (i = 0; i < len - 1; i++) {
            for (j = i + 1; j < len; j++) {
                for(k = 0; k < len; k++) {
                    if (k != i && k != j) {
                        if (isSameLine(points, i, j, k)){
                            sameLineCnt[i][j]++;
                        }
                    }
                }
                if (sameLineCnt[i][j] > res) {
                    res = sameLineCnt[i][j];
                }
            }
        }

        return  res + 2;
    }

    void init(vector<vector<int>> &arr, int len) {
        int i;

        for (i = 0; i < len; i++) {
            arr.push_back(vector<int>(len, 0));
        }
    }

    bool isSameLine(vector<vector<int>>& points, int i, int j, int k) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        int x3 = points[k][0], y3 = points[k][1];

        if (x1 == x2)
            return x2 == x3;
        if (y1 == y2)
            return  y2 == y3;
        return (x2 - x1) * (y3 - y2) == (y2 - y1) * (x3 - x2);
    }
};

int main() {
    Solution sol;
    auto points = vector<vector<int>>({{54,153},{1,3},{0,-72},{-3,3},{12,-22},{-60,-322},{0,-5},{-5,1},{5,5},{36,78},{3,-4},{5,0},{0,4},{-30,-197},{-5,0},{60,178},{0,0},{30,53},{24,28},{4,5},{2,-2},{-18,-147},{-24,-172},{-36,-222},{-42,-247},{2,3},{-12,-122},{-54,-297},{6,-47},{-5,3},{-48,-272},{-4,-2},{3,-2},{0,2},{48,128},{4,3},{2,4}});
    cout << sol.maxPoints(points) << endl;
    return 0;
}
