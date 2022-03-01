#include "../../include/leetcode.hpp"


class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a < b && b < c) {
            return {minMoves(a, b, c), maxMoves(a, b, c)};
        } else if (c < b  && b < a) {
            return {minMoves(c, b, a), maxMoves(c, b, a)};
        } else if (b < a && a < c) {
            return {minMoves(b, a, c), maxMoves(b, a, c)};
        } else if (c < a && a < b) {
            return {minMoves(c, a, b), maxMoves(c, a, b)};
        } else if (a < c && c < b) {
            return {minMoves(a, c, b), maxMoves(a, c, b)};
        } else {
            return {minMoves(b, c, a), maxMoves(b, c, a)};
        }
    }
    
    int minMoves(int a, int b, int c) {
        if (a + 1 == b && b + 1 == c)
            return 0;
        else if (a + 2 >= b || b + 2 >= c)
            return 1;
        else 
            return 2;
    }

    int maxMoves(int a, int b, int c) {
        return (b - a - 1) + (c - b - 1);
    }
};

int main() {
    Solution sol;
    fmt::print("{}\n", sol.numMovesStones(1, 2, 5));
}
