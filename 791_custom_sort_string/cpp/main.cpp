#include "../../include/leetcode.hpp"
#include <functional>

class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> order_map;
        int i = 1;
        for(auto ch : order) {
            order_map[ch] = i;
            i++;
        }

        // fmt::print("{}\n", order_map);
        merge_sort(s, 0, s.size() - 1, [&order_map](const char a, const char b) {
            return order_map[a] - order_map[b];
        });
        // fmt::print("{}\n", order_map);
        return s;
    }
    
    void merge_sort(string &s, int lo, int hi, function<int (const char, const char)> const &comp) {
        if (lo == hi)
            return;
        int mid = (lo + hi) >> 1;
        merge_sort(s, lo, mid, comp);
        merge_sort(s, mid + 1, hi, comp);
        char buf[hi - lo + 1];
        int i = lo, j = mid + 1, k = 0;

        while (i <= mid && j <= hi) {
            // cout << "s[i]" << s[i] << " s[j]"<< s[j] << "  comp "<< comp(s[i], s[j]) << endl;
            if (comp(s[i], s[j]) <= 0) {
                buf[k] = s[i]; 
                i++;
            } else {
                buf[k] = s[j];
                j++;
            }
            k++; 
        }
        while (i <= mid) {
            buf[k] = s[i];
            k++; i++;
        }
        while (j <= hi) {
            buf[k] = s[j];
            k++; j++;
        }
        // fmt::print("s[{}:{}]{}\n", lo, hi, s.substr(lo, hi - lo + 1));
        for (k = 0; k < hi - lo + 1; k++)
            s[k + lo] = buf[k]; 
        // fmt::print("s[{}:{}]{}\n", lo, hi, s.substr(lo, hi - lo + 1));
    }
};

int main() {
    Solution sol;
    cout << sol.customSortString("cba", "abcbbaddef");
}