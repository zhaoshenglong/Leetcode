#include "../../include/leetcode.hpp"

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>> children(parents.size(), vector<int>());        
        vector<int> treeSize(parents.size(), 0);
        int i; 

        for (i = 1; i < parents.size(); i++) {
            children[parents[i]].push_back(i);
        }
        computeTreeSize(children, treeSize, 0);
        
        long long maxScore = 0;
        long long product = 1;
        map<long long, int> scores;
        for (auto child: children[0])
            product *= treeSize[child];

        maxScore = product;
        scores[maxScore]++;
        for (i = 1; i < parents.size(); i++) {
            product = 1;
            product *= treeSize[0] - treeSize[i];
            for (auto child: children[i])
                product *= treeSize[child];
            if (product >= maxScore) {
                maxScore = product;
                scores[maxScore]++;
            }
        }
        return scores[maxScore];
    }

    void computeTreeSize(vector<vector<int>> &children, vector<int>& treeSize, int i) {
        // Only one node
        if (children[i].size() == 0) 
            treeSize[i] = 1;
        int sz = 0;
        for (auto child: children[i]) {
            if (treeSize[child] == 0) {
                computeTreeSize(children, treeSize, child);
            }
            sz += treeSize[child];
        }
        treeSize[i] = sz + 1;
    }
};

int main() {
    Solution sol;
    auto parents = vector<int>({-1,2,0,2,0});
    cout << sol.countHighestScoreNodes(parents) << endl;
}
