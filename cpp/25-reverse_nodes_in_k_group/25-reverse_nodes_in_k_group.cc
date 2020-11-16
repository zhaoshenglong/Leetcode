#include <iostream>
#include <string>

using namespace std;
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *k_tail, *prev_tail, *k_head;
        ListNode *res = nullptr;
        ListNode *p;
        int cnt = 1;
        
        if (k == 1)
            return head;
        k_tail = head;
        k_head = head;
        prev_tail = res;
        while(k_tail) {
            if (cnt == k) {
                cout << "one chain: " << k_head->val << " " << k_tail->val << endl;
                if (!res)
                    res = k_head;
                prev_tail = k_tail;
                k_tail = k_head = k_tail->next;
                cnt = 1;
            } else {
                cout << k_head->val << " " << k_tail->val << endl;
                if (!k_tail->next)
                    break;
                p = k_tail->next;
                k_tail->next = k_tail->next->next;
                p->next = k_head;
                if (prev_tail)
                    prev_tail->next = p; 
                
                k_head = p;
                cnt++;
            }
        }
        if (cnt) {
            if (!res)
                res = this->reverseKGroup(k_head, cnt);
            else
                prev_tail->next = this->reverseKGroup(k_head, cnt);

        }
        return !res ? head : res;
    }
};

void print_list(ListNode *head) {
    ListNode *p = head;
    cout << "[";
    while(p->next) {
        cout << p->val << ", ";
        p = p->next;
    }
    if (p)
       cout << p->val;
    cout << "]" << endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    print_list(head);
    print_list(s.reverseKGroup(head, 3));
}
