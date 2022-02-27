#include "../../include/leetcode.hpp"

class Solution {
public:
    enum DivisionFlag {
        DIVISION_MAX,
        DIVISION_MIN
    };
    char DIVISION_CHR = '/'; 
    char LPAREN_CHR = '('; 
    char RPAREN_CHR = ')'; 

    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1)
            return to_string(nums[0]);
        if (nums.size() == 2) 
            return to_string(nums[0]) + '/' + to_string(nums[1]);
        tuple<bool, float, string> *res[nums.size()];
        init(res, nums.size());

        divisionRecursive(nums, 0, nums.size() - 1, DIVISION_MAX, res);
        string optimal = get<2>(res[0][nums.size() - 1]);
        deinit(res, nums.size());
        return optimal;
    }

    void init(tuple<bool, float, string> *arr[], int len) {
        int i,j;
        for (i = 0; i < len; i++) {
            arr[i] = new tuple<bool, float, string>[len];        
        }
    }

    void deinit(tuple<bool, float, string> *arr[], int len) {
        int i,j;
        for (i = 0; i < len; i++) {
            delete []arr[i];
        }
    }

    float divisionRecursive(vector<int>& nums,
                           int lo, int hi,
                           DivisionFlag flag,
                           tuple<bool, float, string> **res) {
        if (flag == DIVISION_MAX) {
            if (!get<0>(res[lo][hi])) {
                if(lo == hi) { 
                    res[lo][lo] = make_tuple(true, nums[lo], to_string(nums[lo]));
                    return nums[lo];
                } else {
                    float left_max, right_min;
                    float max_r = 0;
                    int max_i;
                    for (int i = lo; i < hi; i++) {
                        left_max = divisionRecursive(nums, lo, i, DIVISION_MAX, res);
                        right_min = divisionRecursive(nums, i + 1, hi, DIVISION_MIN, res);
                        if (left_max / right_min > max_r) {
                            max_r = left_max / right_min;
                            max_i = i;
                        }
                    }
                    string max_str = get<2>(res[lo][max_i]);
                    string min_str = get<2>(res[hi][max_i + 1]);
                    if (max_i + 1 == hi) 
                        res[lo][hi] = make_tuple(true, max_r, max_str + "/" + min_str);
                    else
                        res[lo][hi] = make_tuple(true, max_r, max_str + "/(" + min_str + ")");
                    return max_r;
                }
            } else 
                return get<1>(res[hi][lo]);
        } else {
            if (!get<0>(res[hi][lo])) {
                if (lo == hi) {
                    res[lo][lo] = make_tuple(true, nums[lo], to_string(nums[lo]));
                    return nums[lo];
                } else {
                    float left_min, right_max;
                    float min_r = 1000;
                    int min_i;
                    for (int i = lo; i < hi; i++) {
                        left_min = divisionRecursive(nums, lo, i, DIVISION_MIN, res);
                        right_max = divisionRecursive(nums, i + 1, hi, DIVISION_MAX, res);
                        if (left_min / right_max < min_r) {
                            min_r = left_min / right_max;
                            min_i = i;
                        }
                    }
                    string min_str = get<2>(res[min_i][lo]);
                    string max_str = get<2>(res[min_i + 1][hi]);
                    if (min_i + 1 == hi) 
                        res[hi][lo] = make_tuple(true, min_r, min_str + "/" + max_str);
                    else
                        res[hi][lo] = make_tuple(true, min_r, min_str + "/(" + max_str + ")");
                    return min_r;
                }
            } else
                return get<1>(res[hi][lo]);
        }
    }
};

int main() {
    auto solution = Solution();
    auto nums = vector<int>({1000, 100, 10, 2});
    cout << solution.optimalDivision(nums) << endl;
}
