#include "../include/leetcode.hpp"

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(d + 1, vector<int>(n + 1));
        vector<vector<int>> suffix(n + 1, vector<int>(n + 1));
        if (d > n)
            return -1;

        int i, j, k;
        // compute suffix difficulty with day == 1
        for (i = n; i >= 1; i--) {
            suffix[i][i] = jobDifficulty[i - 1];
            for (j = i + 1; j <= n; j++) {
                suffix[i][j] = max(suffix[i][j - 1], jobDifficulty[j - 1]);
            }
        }
        fmt::print("{}\n", suffix);
        // compute prefix difficulty with day == 1
        dp[1][1] = jobDifficulty[0];
        for (j = 2; j <= n; j++) {
            dp[1][j] = max(dp[1][j - 1], jobDifficulty[j - 1]);
        }
        for (i = 2; i <= d; i++) {
            for (j = i; j <= n; j++) {
                dp[i][j] = INT_MAX;
                for (k = i - 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + suffix[k + 1][j]);
                }
            }
        }

        fmt::print("{}\n", dp);
        return dp[d][n];
    }
};

int main() {
    Solution sol;
    auto difficulty = vector<int>({6,5,4,3,2,1});
    cout << sol.minDifficulty(difficulty, 2) << endl;
}
