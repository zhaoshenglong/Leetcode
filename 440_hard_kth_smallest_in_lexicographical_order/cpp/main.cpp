#include "../../include/leetcode.hpp"

class Solution {
    int findKthNumRecursive(int root, int nodeCnt, int k) {
        if (k == 1)
            return root;
        if (nodeCnt < 10)
            return root * 10 + (k - 2);
        
        nodeCnt -= 1;
        k -= 1;
        int depth = log10(nodeCnt * 9 + 1) - 1;
        int fullLeaves = pow(10, depth);
        int nodesWithoutLastLevel = (fullLeaves - 1) / 9;
        int totalLeaves = nodeCnt - nodesWithoutLastLevel * 10;
        int fullBranchIdx = totalLeaves / fullLeaves;
        int remainLeaves = totalLeaves - fullBranchIdx * fullLeaves;

        int nextBranch = 0;
        int nextNodeCnt;
        for(; nextBranch <= 9; nextBranch++) {
            if (nextBranch < fullBranchIdx) {
                if (k > fullLeaves + nodesWithoutLastLevel) {
                    k -= fullLeaves + nodesWithoutLastLevel;
                } else {
                    nextNodeCnt = fullLeaves + nodesWithoutLastLevel;
                    break;
                }
            } else if (nextBranch == fullBranchIdx) {
                if (k > remainLeaves + nodesWithoutLastLevel) {
                    k -= remainLeaves + nodesWithoutLastLevel;
                } else {
                    nextNodeCnt = remainLeaves + nodesWithoutLastLevel;
                    break;
                }
            } else {
                if (k > nodesWithoutLastLevel) {
                    k -= nodesWithoutLastLevel;
                } else {
                    nextNodeCnt = nodesWithoutLastLevel;
                    break;
                }
            }
        }

        return findKthNumRecursive(root * 10 + nextBranch, nextNodeCnt, k);
    }

public:
    int findKthNumber(int n, int k) {
        if(n < 10)
            return k;
        int depth = log10(n);
        int fullLeaves = pow(10, depth);
        int nodesWithoutLastLevel = (fullLeaves - 1) / 9;
        int totalLeaves = n - nodesWithoutLastLevel * 9;
        int fullBranchIdx = totalLeaves / fullLeaves;
        int remainLeaves = totalLeaves - fullBranchIdx * fullLeaves;

        int nextBranch = 1;
        int nextNodeCnt;
        for (; nextBranch < 10; nextBranch++) {
            if (nextBranch <= fullBranchIdx) {
                if (k > fullLeaves + nodesWithoutLastLevel) {
                    k -= fullLeaves + nodesWithoutLastLevel;
                } else {
                    nextNodeCnt = fullLeaves + nodesWithoutLastLevel;
                    break;
                }
            } else if (nextBranch == fullBranchIdx + 1) {
                if (k > remainLeaves + nodesWithoutLastLevel) {
                    k -= remainLeaves + nodesWithoutLastLevel;
                } else {
                    nextNodeCnt = remainLeaves + nodesWithoutLastLevel;
                    break;
                }
            } else {
                if (k > nodesWithoutLastLevel) {
                    k -= nodesWithoutLastLevel;
                } else {
                    nextNodeCnt = nodesWithoutLastLevel;
                    break;
                }
            }
        }

        return findKthNumRecursive(nextBranch, nextNodeCnt, k);
    }
};

int main() {
    Solution sol;
    cout << sol.findKthNumber(13, 2) << endl;
}
