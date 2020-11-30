#include <iostream>
#include <vector>
#include "../include/read_x.hpp"

using namespace std;

static inline int find_include_last_rec(vector<int>& heights, int hi, int &maxh) {
    long h;
    long area, maxarea;
    long i, maxi;

    h = maxh = heights[hi];
    maxarea = h;
    for (i = hi - 1; i >= 0; i--) {
        if(heights[i] < h) {
            if((h - heights[i]) * (hi - i) >= heights[i] * (i + 1) ||
                (hi - maxi + 1) * (maxh - h) >= heights[i] * (i + 1)) {
                break;
            } else {
                h = heights[i];
                if ( (area = h * (hi - i + 1)) > maxarea) {
                    maxarea = area;
                    maxh = h;
                    maxi = i;
                }
            }
        } else {
            if ( (area = h * (hi - i + 1)) > maxarea) {
                maxarea = area;
                maxh = h;
                maxi = i;
            }
        }
    }
    return maxarea;
}

class Solution {
public:
    int bruteforce(vector<int>& heights) {
        int area, max_area;
        int sz = heights.size();
        int i;
        int h, maxh;

        if (!sz)
            return 0;
        maxh = h = max_area = heights[0];
        
        for (i = 1; i < sz - 1; i++) {
            if (heights[i + 1] >= heights[i])
                continue;
            else {
                area = find_include_last_rec(heights, i, h);
                if (area > max_area) {
                    maxh = h;
                    max_area = area;
                }
            }
            if (heights[i] < heights[i - 1]) {
                area = find_include_last_rec(heights, sz - 1, h);
                if (area > max_area) {
                    maxh = h;
                    max_area = area;
                }
            } 
        }

        area = find_include_last_rec(heights, sz - 1, h);
        if (area > max_area)
            max_area = area;
        return max_area;
    }

    int largestRectangleArea(vector<int>& heights) {
        return bruteforce(heights);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> heights;

    heights = read_vec("input.txt");
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}
