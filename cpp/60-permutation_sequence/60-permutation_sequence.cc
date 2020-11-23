#include <iostream>
#include <string>
#include <vector>

using namespace std;

static inline char findKth(vector<int>& nums, int k) {
    int i;
    char res;

    for (i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != 0) {
            k--;
            if (k == 0) {
                res = (char)(nums[i] + '0');
                nums[i] = 0;
                return res;
            }
        }
    } 
    return '0';
}

static inline int fact(int n) {
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int i;
        int nfact;
        string s(n, '0');

        for (i = 0; i < n; i++)
            nums.push_back(i + 1);
        
        for (i = 0; i < n; i++) {
            if (k == 0) {
                s[i] = findKth(nums, n - i);
            } else {
                nfact = fact(n - i - 1);
                s[i] = findKth(nums, (k + nfact - 1) / nfact);
                k -= k / nfact * nfact;
            }
        }
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n, k;
    
    if (argc < 3) {
        printf("Usage: %s <n> <k>\n", argv[0]);
        exit(0);
    }

    n = atoi(argv[1]);
    k = atoi(argv[2]);
    cout << s.getPermutation(n, k) << endl;
    return 0;
}
