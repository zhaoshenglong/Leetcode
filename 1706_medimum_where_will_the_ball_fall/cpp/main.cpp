#include "../../include/leetcode.hpp"

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        auto m = grid.size(), n = grid[0].size();
        auto location = vector<int>(n, 0);
        set<int> invalidSet;
        int i, j, col;

        init(location);
        for (i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                col = location[j];
                if (col >= 1 && col <= n - 2) {
                    if (grid[i][col] == 1 && grid[i][col + 1] == 1) {
                        location[j] = col + 1; 
                    } else if (grid[i][col] == -1 && grid[i][col - 1] == -1) {
                        location[j] = col - 1;
                    } else {
                        invalidSet.insert(j);
                    }
                } else if (col == 0 ){
                    if (grid[i][0] == 1 && n >= 2 && grid[i][1] == 1) {
                        location[j] = 1;
                    } else {
                        invalidSet.insert(j);
                    }
                } else {
                    if (grid[i][n - 1] == -1 && n >= 2 && grid[i][n - 2] == -1) {
                        location[j] = n - 2;
                    } else {
                        invalidSet.insert(j);
                    }
                }
            }
        }
        
        for(auto i : invalidSet)
            location[i] = -1;
        return location;
    }

    void init(vector<int> &v) {
        int i;
        for(i = 0; i < v.size(); i++) {
            v[i] = i;
        }
    }
};

int main() {
    auto solution = Solution();
    auto grid = vector<vector<int>>({{1,1,1,-1,-1}, {1,1,1,-1,-1}, {-1,-1,-1,1,1}, {1,1,1,1,-1}, {-1,-1,-1,-1,-1}});
    fmt::print("{}\n", solution.findBall(grid));
    return 0;
}
