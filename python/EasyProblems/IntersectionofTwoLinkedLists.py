# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        sz_a = 0
        sz_b = 0
        p = headA
        q = headB
        while p and q:
            sz_a += 1
            sz_b += 1
            p = p.next
            q = q.next
        while p:
            sz_a += 1
            p = p.next
        while q:
            sz_b += 1
            q = q.next
        t = sz_b - sz_a
        p = headA
        q = headB
        while t > 0:
            q = q.next
            t -= 1
        while t < 0:
            p = p.next
            t += 1
        while p:
            if p == q:
                return p
            p = p.next
            q = q.next
