#include "../../include/leetcode.hpp"

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> digitCount(11, 0);
        int n = secret.size();
        int bulls = 0, cows = 0;
        int i;

        for (i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                guess[i] = 58;
                bulls++;
            } else {
                digitCount[secret[i] - '0']++;
            }
        }
        for (auto c: guess) {
            if (digitCount[c - '0'] > 0) {
                digitCount[c - '0']--;
                cows++;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
