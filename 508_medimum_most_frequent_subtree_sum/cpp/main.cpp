/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "../../include/leetcode.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> sumFreq;
        vector<set<int>> freqSum = {{}};
        
        findSumFreqRecursive(root, sumFreq, freqSum);
        
        return vector<int>(freqSum.back().begin(), freqSum.back().end());
    }
    
    int findSumFreqRecursive(TreeNode* node, map<int, int>& sumFreq, vector<set<int>> &freqSum) {
        if (!node)
            return 0;
        int ls = findSumFreqRecursive(node->left, sumFreq, freqSum);
        int rs = findSumFreqRecursive(node->right, sumFreq, freqSum);;
        int seqSum = ls + rs + node->val;
        sumFreq[seqSum] += 1;
        if (sumFreq[seqSum] == freqSum.size()) {
            freqSum.push_back({seqSum});
        } else {
            freqSum[sumFreq[seqSum]].insert(seqSum);
        }
        return seqSum;
    }
    
};