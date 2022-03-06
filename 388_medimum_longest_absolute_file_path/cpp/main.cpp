#include "../../include/leetcode.hpp"

class Solution {
public:
    int pos = 0;
    int lengthLongestPath(string input) {
        int res = 0;
        vector<int> dirLen = {0};
        bool isDir;
        int level, len;
        
        while(pos < input.size()) {
            skipNewLine(input);
            level = getLevel(input);
            len = getLenOfName(input, isDir);
            if (!isDir && len + dirLen[level - 1] > res) {
                res = len + dirLen[level - 1];
            } else {
                if (dirLen.size() <= level)
                    dirLen.push_back(dirLen[level - 1] + len + 1);
                else
                    dirLen[level] = dirLen[level - 1] + len + 1;
            }
        }
        return res;
    }
    
    void skipNewLine(string &s) {
        if(pos < s.size() && s[pos] == '\n')
            pos ++;
    }
    
    int getLevel(string &s) {
        int level = 1;
        while(pos < s.size() && s[pos] == '\t') {
            level++;
            pos  ++;
        }
        // cout << "level: "<< level << " pos: " << s[pos] << endl;
        return level;
    }
    
    // make sure start from a file or directory name
    int getLenOfName(string &s, bool &isDir) {
        int len = 0;
        isDir = true;
        int i = pos;
        while(pos < s.size() && s[pos] != '\n') {
            if(s[pos] == '.')
                isDir = false;
            pos++;
            len++;
        }
        // cout << s.substr(i, pos) << " len:" << len << endl;
        return len;
    }
};