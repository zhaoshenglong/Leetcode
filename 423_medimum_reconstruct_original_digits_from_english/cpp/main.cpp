#include "../../include/leetcode.hpp"

class Solution {
public:
    string originalDigits(string s) {
        int letterCnt[10];
        map<char, int> charCnt;

        for(auto ch: s)
            charCnt[ch]++;
        letterCnt[0] = charCnt['z'];
        letterCnt[2] = charCnt['w'];
        letterCnt[4] = charCnt['u'];
        letterCnt[6] = charCnt['x'];
        letterCnt[8] = charCnt['g'];

        letterCnt[1] = charCnt['o'] - (charCnt['z'] + charCnt['w'] + charCnt['u']);
        letterCnt[3] = charCnt['t'] - (charCnt['w'] + charCnt['g']);
        letterCnt[5] = charCnt['f'] - charCnt['u'];
        letterCnt[7] = charCnt['s'] - charCnt['x'];
        letterCnt[9] = charCnt['i'] - (letterCnt[5] + letterCnt[6] + letterCnt[8]);
        int letter = '0';
        string res = "";
        for(auto len: letterCnt) {
            res += string(len, letter);
            letter++;
        }
        return res;
    }
};
