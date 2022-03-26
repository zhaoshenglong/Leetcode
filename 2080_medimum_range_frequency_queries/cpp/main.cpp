#include "../../include/leetcode.hpp"

class RangeFreqQuery {
    unordered_map<int, vector<int>> prefixes;
public:
    RangeFreqQuery(vector<int>& arr) {
        int i;
        for (i = 0; i < arr.size(); i++) {
            if (prefixes[arr[i]].empty())
                prefixes[arr[i]].push_back(0);
            prefixes[arr[i]].push_back(i);
        }
        fmt::print("{}\n", prefixes);
    }

    int query(int left, int right, int value) {
        const auto &prefix = prefixes[value];
        fmt::print("{}\n", prefix);
        auto lo = bsearch(prefix, left);
        auto hi = bsearch(prefix, right);
        
        return hi - lo;
    }

    int bsearch(const vector<int>& arr, int target) {
        int lo = 0, hi = arr.size();

        while(lo < hi) {
            int mid = (lo + hi) >> 1;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo - 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main() {
    auto arr = vector<int>({12,33,4,56,22,2,34,33,22,12,34,56});
    RangeFreqQuery query(arr);

    cout << query.query(1, 2, 4) << endl;
    cout << query.query(0, 11, 33) << endl;
}
