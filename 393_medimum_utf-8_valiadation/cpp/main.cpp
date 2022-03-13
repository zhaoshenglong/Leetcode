#include "../../include/leetcode.hpp"


class Solution {
public:
    const enum UTF_OCTET {
        OneByteMin = 0x0,
        OneByteMax = 0x7f,
        TwoByteMin = 0xc0,
        TwoByteMax = 0xdf,
        ThreeByteMin = 0xe0,
        ThreeByteMax = 0xef,
        FourByteMin = 0xf0,
        FourByteMax = 0xf7,
        SuffixByteMin = 0x80
    };

    bool validUtf8(vector<int>& data) {
        int len;
        int byte;
        int i, j;
        
        len = data.size();
        i = 0;
        while(i < len) {
            byte = data[i];
            if (byte <= OneByteMax && byte >= OneByteMin) {
                i++;
                continue;
            } else if (byte <= TwoByteMax && byte >= TwoByteMin) {
                if (i + 1 < len && data[i + 1] >= SuffixByteMin) {
                    i += 2;
                    continue;
                }
                return false;
            } else if (byte <= ThreeByteMax && byte >= ThreeByteMin) {
                if (i + 2 < len) {
                    if (data[i + 1] >= SuffixByteMin &&
                        data[i + 2] >= SuffixByteMin) {
                        i += 3;
                        continue;
                    }
                }
                return false;
            } else if (byte <= FourByteMax && byte >= FourByteMin) {
                if (i + 3 < len) {
                    if (data[i + 1] >= SuffixByteMin &&
                        data[i + 2] >= SuffixByteMin &&
                        data[i + 3] >= SuffixByteMin) {
                        i += 4;
                        continue;
                    }
                }
                return false;
            } else {
                return false;
            }
        }
        return true;
    }
};
