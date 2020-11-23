#include <iostream>
#include <string>
#include <vector>
#include "../include/print_x.hpp"

#define DIAG(r, c)          ((r) + (c))
#define BACKDIAG(n, r, c)   ((c) + (n - 1) - (r))

using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cols(n, 0);
        vector<int> diag(2 * n - 1, 0);
        vector<int> backdiag(2 * n - 1, 0);
        vector<string> vec;

        backtrack(n, 0, cols, diag, backdiag, vec, res);
        return res;
    }
    
    void backtrack(int n, int r, vector<int>& cols, vector<int>& diag, vector<int>& backdiag, vector<string>& res, vector<vector<string>>& resvec) {
        int c;
        int i;
        string s;

        if (r == n - 1) {
            for (i = 0; i < n; i++)
                if (!cols[i])
                    c = i;
            if (!diag[DIAG(r, c)] && !backdiag[BACKDIAG(n, r, c)]) {
                s = string(n, '.');
                s[c] = 'Q';
                res.push_back(s);
                resvec.push_back(res);
                res.pop_back();
                return;
            }
        } else {
            s = string(n, '.');
            for (i = 0; i < n; i++) {
                if (!cols[i]) {
                    c = i;
                    if (!diag[DIAG(r, c)] && !backdiag[BACKDIAG(n, r, c)]) {
                        cols[c] = 1;
                        diag[DIAG(r, c)] = 1;
                        backdiag[BACKDIAG(n, r, c)] = 1;
                        s[c] = 'Q';
                        res.push_back(s);
                        backtrack(n, r + 1, cols, diag, backdiag, res, resvec);
                        res.pop_back();
                        s[c] = '.';
                        diag[DIAG(r, c)] = 0;
                        backdiag[BACKDIAG(n, r, c)] = 0;
                        cols[c] = 0;
                    }
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n;

    if (argc < 2) {
        printf("Usage: %s <n>\n", argv[0]);
        exit(1);
    }
    
    n = atoi(argv[1]);
    cout << s.solveNQueens(n) << endl;
    return 0;
}
