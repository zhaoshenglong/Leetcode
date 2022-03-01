#include "../../include/leetcode.hpp"

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int len = s.size(), batch_size = (numRows << 1) - 2;
        int i,j;

        if (numRows == 1)
            return s;
        for (i = 0; i < numRows; i++) {
            for (j = i; j < len; j += batch_size) {
                res.push_back(s[j]);
                if (i != 0 && i != numRows - 1 && j + batch_size - i * 2 < len)
                    res.push_back(s[j + batch_size - i * 2]);
            }
        }
        return res;
    }
};

int main() {

    Solution solution;
    string s = "A";
    auto nrows = 1;
    cout << solution.convert(s, nrows) << endl;
    return 0;
}
