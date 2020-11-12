#include <iostream>
#include <vector>
#include <map>
#include "../include/print_x.hpp"

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        map<int, int> candidates;
        map<int, int>::iterator it, cand_1, cand_2;
        int cnt_cand_1 = 0, cnt_cand_2 = 0;
        int i;
        int sz = nums.size();

        for (i = 0; i < sz; i++) {
            if (candidates.size() < 2) {
                if (candidates.find(nums[i]) != candidates.end())
                    candidates[nums[i]]++;
                else
                    candidates[nums[i]] = 1;    
            } else {
                it = candidates.find(nums[i]);
                if (it != candidates.end())
                    candidates[nums[i]]++;
                else {
                    cand_1 = candidates.begin();
                    cand_2 = next(cand_1);
                    cand_1->second--;
                    cand_2->second--;
                    if (!cand_1->second)
                        candidates.erase(cand_1);
                    if (!cand_2->second)
                        candidates.erase(cand_2);
                }
            }
        }
        if (candidates.empty())
            return res;

        cand_1 = candidates.begin();
        cand_2 = next(cand_1);
        for (i = 0; i < sz; i++) {
            if (nums[i] == cand_1->first)
                cnt_cand_1++;
            else if (cand_2 != candidates.end() && cand_2->first == nums[i])
                cnt_cand_2++;
        }
        if (cnt_cand_1 > sz / 3)
            res.push_back(cand_1->first);
        if (cnt_cand_2 > sz / 3)
            res.push_back(cand_2->first);
        return res;
    }
};

int main(int argc, char **argv){
    int narr[] = {4,1,3,1,3,3,1,2,3,2,4,2,1,4,4,4,4,4};
    vector<int> nums(narr, narr + 18);
    Solution s;
    cout << nums << endl;
    cout << s.majorityElement(nums) << endl;
    return 0;
}
