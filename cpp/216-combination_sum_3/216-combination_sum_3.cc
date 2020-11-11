#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec){
    auto it = vec.begin();

    os << "[";
    for(; it != vec.end() && it + 1 != vec.end(); it++)
        os << *it << ", ";
    if (it != vec.end())
        os << *it;
    os << "]";
    return os;
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        int min_sum[10] = {0, 0, 3, 6, 10, 15, 21, 28, 36, 45};
        int tmp[k];

        if (n < min_sum[k])
            return res;
        
        recursive_sum(res, k - 1, 0, 0, n, tmp); 
        return res;
    }

    void recursive_sum(vector<vector<int> > &vec, int k, int idx, int s, int n, int *tmp) {
        int i;
        if (s > n)
            return;
        if (!k) {
            for (i = tmp[idx - 1] + 1; i <= 9; i++) {
                /* cout << "i = " << i << " s = " << s << endl; */
                if (s + i == n){
                    tmp[idx] = i;
                    vec.push_back(vector<int>(tmp, tmp + idx + 1));
                    /* cout << vec << endl; */
                }
                else if (s + i > n)
                    break;
            }
        } else {
            if (!idx)
                i = 1;
            else
                i = tmp[idx - 1] + 1;
            for (; i <= 10 - k; i++) {
                tmp[idx] = i;
                recursive_sum(vec, k - 1, idx + 1, s + i, n, tmp);
            }
        }
    }
};

int main() {
    Solution s;
    int k = 2;
    int n = 5;

    cout << s.combinationSum3(k, n) << endl;
    return 0;
}
