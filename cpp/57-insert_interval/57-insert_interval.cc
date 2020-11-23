#include <iostream>
#include <vector>
#include "../include/print_x.hpp"

using namespace std;

static inline int find_pos(vector<vector<int>>& intervals, int val, bool& found) {
    int lo = 0, hi = intervals.size(), mid;
    
    found = false;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (intervals[mid][0] <= val && intervals[mid][1] >= val) {
            found = true;
            return mid;
        }    
        if (intervals[mid][0] > val)
            hi = mid;
        else if (intervals[mid][1] < val)
            lo = mid + 1;
    }
    return (lo + hi) >> 1;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i, j;
        bool found;
        i = find_pos(intervals, newInterval[0], found);

        res.insert(res.begin(), intervals.begin(), intervals.begin() + i);
        res.push_back(newInterval);
        if (found) {
            res.back()[0] = intervals[i][0];
        }

        j = find_pos(intervals, newInterval[1], found);
        if (found) {
            res.back()[1] = intervals[j][1];
            res.insert(res.end(), intervals.begin() + j + 1, intervals.end());
        } else {
            res.insert(res.end(), intervals.begin() + j, intervals.end());
        }
        return res;
    }
};

void initial(vector<vector<int>> &intervals) {
    int a[] = {1, 3};
    int b[] = {6, 9};

    intervals.push_back(vector<int>(a, a + 2));
    intervals.push_back(vector<int>(b, b + 2));
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> intervals;
    int ni[] = {5, 7};
    vector<int> newInterval(ni, ni + 2);

    initial(intervals);
    cout << s.insert(intervals, newInterval) << endl;
    return 0;
}
