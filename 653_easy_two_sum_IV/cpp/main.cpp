#include "../../include/leetcode.hpp"


// Definition for a binary tree node.
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        preTraverse(root, vec);
        return findSum(vec, k);
    }

    void preTraverse(TreeNode *node, vector<int>&vec) {
        if (!node)
            return;
        preTraverse(node->left, vec);
        vec.push_back(node->val);
        preTraverse(node->right, vec);
    }

    bool findSum(vector<int>&vec, int target) {
        int i = 0, j = vec.size() - 1;

        while (i < j) {
            if (vec[i] + vec[j] == target)
                return true;
            else if (vec[i] + vec[j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
