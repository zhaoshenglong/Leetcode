#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int lo = 0, hi = s.size() - 1;
        char temp;
        while(lo < hi) {
            while(lo < hi && !isalpha(s[lo]))
                lo++;
            while(hi > lo && !isalpha(s[hi]))
                hi--;
            temp = s[lo];
            s[lo] = s[hi];
            s[hi] = temp;
            lo++;
            hi--;
        }
        return s;
    }
};

int main() {
    Solution s = Solution();
    string str = "a-bC-dEf-ghIj";
    cout << s.reverseOnlyLetters(str) << endl;
}
