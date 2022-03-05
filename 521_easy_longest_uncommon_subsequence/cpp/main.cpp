#include "../../include/leetcode.hpp"

class Solution {
public:
    int findLUSlength(string a, string b) {
        int as = a.size(), bs = b.size();
        if (as > bs)
            return as;
        if (as < bs)
            return bs;
        if(a != b)
            return as;
        return -1;
    }
};