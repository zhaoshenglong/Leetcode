#include "../../include/leetcode.hpp"

class Solution {
public:
    bool winnerOfGame(string colors) {
        int A = 0, B = 0;
        int prefixA = 0, prefixB = 0;
        for (auto c: colors) {
            if (c == 'A') {
                if (prefixA >= 2) {
                    A++;
                } else {
                    prefixA++;
                    prefixB = 0;
                }
            } else {
                if (prefixB >= 2) {
                    B++; 
                } else {
                    prefixB++;
                    prefixA = 0;
                }
            }
        }

        return A > B ? true: false;
    }
};

