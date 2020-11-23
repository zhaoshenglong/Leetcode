#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int i;
        int res[s.size()];
        int max_res = 0;
        
        res[0] = 0;
        for (i = 1; i < (int)s.size(); i++) {
            res[i] = 0;

            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    res[i] = 2;
                    if (i - 2 >= 0)
                        res[i] += res[i - 2];
                } else if (res[i - 1] > 0 && i - 1 - res[i - 1] >= 0 && s[i - 1 - res[i - 1]] == '(') {
                    res[i] = 2;
                    res[i] += res[i - 1];
                    if (i - 2 - res[i - 1] >= 0)
                        res[i] += res[i - 2 - res[i - 1]];
                }
            }

            if (res[i] > max_res)
                max_res = res[i];
        }

        return max_res;
    }

};

int main(int argc, char *argv[]) {
    Solution s;
    string str(")()())");

    cout << s.longestValidParentheses(str) << endl; 
    return 0;
}
