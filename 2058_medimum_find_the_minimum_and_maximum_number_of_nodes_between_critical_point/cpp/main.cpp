#include "../../include/leetcode.hpp"


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *cur, *prev;
        int firstNode = -1, prevNode = -2;
        int minDist = 100000;
        int cnt = 1;
        int nodeCnt = 0;
        
        prev = head, cur = head->next;
        while(cur->next) {
            if (isCritical(cur, prev)) {
                if (firstNode < 0)
                    firstNode = cnt;
                if (prevNode > 0 && cnt - prevNode < minDist)
                    minDist = cnt - prevNode;
                prevNode = cnt;
                nodeCnt++;
            }
            prev = cur;
            cur = cur->next;
            cnt++;
        }

        if (nodeCnt >= 2)
            return {minDist, prevNode - firstNode}; 
        else
            return {-1, -1};
    }

    bool isCritical(ListNode *cur, ListNode *prev) {
        return (cur->val > cur->next->val && cur->val > prev->val)
            || (cur->val < cur->next->val && cur->val < prev->val);
    }

};

