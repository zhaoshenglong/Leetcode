#include "../../include/leetcode.hpp"

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxSize = -1;
        int pos = 0;
        int i;
        for (auto& s: strs) {
            for (i = 0; i < strs.size(); i++) {
                if (i == pos || strs[i].size() < s.size())
                    continue;
                if (isSubsequence(s, strs[i]))
                    break;
            }
            if (i == strs.size())
                maxSize = max(maxSize, (int)s.size());
            pos++;
        }
        return maxSize; 
    }

    bool isSubsequence(const string& a, const string& b) {
        int i, lo = 0;
        for (auto ch: a) {
            for (i = lo; i < b.size(); i++) {
                if (b[i] == ch) {
                    lo = i + 1;
                    break;
                }
            }
            if (i == b.size())
                return false;
        }
        return true;
    }
};

