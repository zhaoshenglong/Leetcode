#include "../../include/leetcode.hpp"


class Solution {
public:
    vector<int> areaSum;
    vector<vector<int>> rectangles;
    Solution(vector<vector<int>>& rects) {
        int area = 0;
        for (auto &rect : rects) {
            area += (rect[3] - rect[1]) * (rect[2] - rect[0]) + rect[3] - rect[1] + rect[2] - rect[0] + 1;
            areaSum.push_back(area);
        }
        rectangles = rects;
    }

    vector<int> pick() {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<std::mt19937::result_type> dist(0,areaSum.back());
        
        int choice = dist(rng);
        int index = find_first_large_of(areaSum, choice);

        int x, y;
        uniform_int_distribution<std::mt19937::result_type> xdist(0,
                rectangles[index][2] - rectangles[index][0]);
        uniform_int_distribution<std::mt19937::result_type> ydist(0,
                rectangles[index][3] - rectangles[index][1]);
        x = xdist(rng) + rectangles[index][0];
        y = ydist(rng) + rectangles[index][1];
        return {x, y};
    }

    int find_first_large_of(vector<int> &vec, int target) {
        int lo = 0, hi = vec.size();
        while(lo < hi) {
            int mid = (lo + hi) >> 1;
            if (vec[mid] > target) {
                hi = mid;
                continue;
            }
            if (vec[mid] < target) {
                lo = mid + 1;
                continue;
            }
            return mid;
        }
        return hi;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

