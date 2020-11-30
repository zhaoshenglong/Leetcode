#include <iostream>
#include <vector>
#include "../include/print_x.hpp"

using namespace std;

#define min(x, y)       ((x) < (y) ? (x) : (y))
#define max(x, y)       ((x) > (y) ? (x) : (y))

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        int dp[sz1 + 1][sz2 + 1];
        int i, j, k;
        
        dp[0][0] = 0;
        for (i = 1; i <= min(sz1, sz2); i++) {
            dp[i][0] = i;
            dp[0][i] = i;
        }
        if (sz1 < sz2) {
            for (i = sz1 + 1; i <= sz2; i++)
                dp[0][i] = i;
        } else {
            for (i = sz2 + 1; i <= sz1; i++)
                dp[i][0] = i;
        }
        
        for (i = 1; i <= sz1; i++) {
            // dp[i][j] represents number of ops for transforming word1[:i] to word2[:j]
            // word1[:i] and word2[:j] is right exclusive
            // e.g. i = 3 & word1 = "abcd", then word1[:3] means "abc"

            for (j = 1; j <= sz2; j++) {
                dp[i][j] = dp[i - 1][j] + 1;    // remove word1[i] (1 step)
                for (k = 0; k < j; k++) {
                    // replace word1[i - 1] with word2[k]
                    // transform word1[:i - 1] to word2[:k]
                    // insert (j - k - 1) characters after word1[i - 1]

                    if (dp[i - 1][k] + 1 + (j - k - 1) <= dp[i][j]) {
                        dp[i][j] = dp[i - 1][k] + 1 + (j - k - 1);
                        if (word1[i - 1] == word2[k])
                            dp[i][j] --;
                    }        
                }
            }
        }

        for (i = 0; i <= sz1; i++){
            for (j = 0; j <= sz2; j++) {
                cout << " " << dp[i][j];
            }
            cout << endl;
        } 
        return dp[sz1][sz2];
    }
};

int main(int argc, char *argv[]) {
    string s1("plasma"), s2("altruism");
    Solution s;

    cout << s.minDistance(s1, s2) << endl;
    return 0;
}
