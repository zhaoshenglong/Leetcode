#include "../../include/leetcode.hpp"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> nodes;
        vector<int> res;

        if (!root)
            return {};
        nodes.push(root);
        while(!nodes.empty()) {
            Node *node = nodes.top();
            nodes.pop();
            res.push_back(node->val);
            auto it = node->children.rbegin();
            while(it != node->children.rend()) {
                nodes.push(*it);
                it++;
            }
        }
        return res;
    }
};
