#include "../include/leetcode.hpp"


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
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<int, Node *>> Q;
        vector<vector<int>> res;

        if (!root)
            return res;
        Q.push({0, root});

        while(!Q.empty()) {
            auto [h, p] = Q.front();
            Q.pop();
            
            if (res.size() == h) {
                res.push_back({});
            }
            res[h].push_back(p->val);
            for(auto c: p->children) {
                Q.push({h + 1, c});
            }
        }
        return res;
    }
};
