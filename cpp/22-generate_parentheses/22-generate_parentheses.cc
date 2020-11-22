#include <iostream>
#include <string>
#include <vector>
#include "../include/print_x.hpp"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int i;
        
        if (n == 0)
            return res;
        if (n == 1) {
            res.push_back(string("()"));
            return res;
        }
        for (string s: generateParenthesis(n - 1)) {
            s.insert(0, "(");
            res.push_back(s + ")");
            s.insert(1, ")");
            res.push_back(s);
        }
        for (i = 1; i < n - 1; i++) {
            for (string prefix: generateParenthesis(i)) {
                prefix.insert(0, "(");
                prefix.append(")");
                for (string suffix : generateParenthesis(n - i - 1)) {
                    res.push_back(prefix + suffix);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    int n;
    Solution s;

    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        exit(0);
    }

    n = atoi(argv[1]);
    cout << s.generateParenthesis(n) << endl;
    return 0;
}
