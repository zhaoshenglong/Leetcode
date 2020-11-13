#include <iostream>
#include <string>

using namespace std;

#define IS_STAR(c)          ((c) == '*')
#define IS_POINT(c)         ((c) == '.')
#define IS_ALPHA(c)         ((c) <= 'z' && (c) >= 'a')

class Solution {
public:
    bool isMatch(string s, string p) {
        return this->isMatchBT(s, 0, p, 0);
    }

    bool isMatchBT(string s, int i, string p, int j) {
        int s_sz = s.size(), p_sz = p.size();
        int k;

        while (i < s_sz && j < p_sz) {
            if (IS_POINT(p[j])) {
                if (j + 1 < p_sz && IS_STAR(p[j + 1])) {
                    if (isMatchBT(s, i, p, j + 2))
                        return true;

                    for (k = i; k < s_sz; k++)
                        if (isMatchBT(s, k + 1, p, j + 2))
                            return true;
                    return false;
                } else {
                    i++;
                    j++;
                }
            } else if (IS_ALPHA(p[j])) {
                if (j + 1 < p_sz && IS_STAR(p[j + 1])) {
                    /* cout << "is star " << j << endl; */
                    if (isMatchBT(s, i, p, j + 2))
                        return true;
                    else {
                        /* cout << "*(zero repeat doesn't match)" << endl; */
                        for (k = i; k < s_sz && s[k] == p[j]; k++) {
                            /* printf("str: %s %d %d, pattern: %s %d %d\n", s.data(), i, s_sz, p.data(), j, p_sz); */
                            if (isMatchBT(s, k + 1, p, j + 2))
                                return true;
                        }
                    }
                    return false;
                } else {
                    if (s[i] == p[j]) {
                        i++;
                        j++;
                    } else 
                        return false;
                }
            }
        }
         
        if (i == s_sz && j != p_sz) {
            while (j < p_sz)
                if (j + 1 < p_sz && IS_STAR(p[j + 1]))
                    j += 2;
                else 
                    break;
        }
        return i == s_sz && j == p_sz;
    } 
};

int main(int argc, char **argv) {
    string str, pattern;
    Solution s;
    if (argc < 3) {
        printf("Usage %s <str> <pattern>\n", argv[0]);
        exit(0);
    }
    
    
    /* printf("str: %s, pattern: %s\n", argv[1], argv[2]); */
    str = string(argv[1]);
    pattern = string(argv[2]);
    cout << s.isMatch(str, pattern) << endl;
}
