# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        res = ListNode(1)
        res.next = head
        prev = res
        while prev:
            p = prev.next
            if not p:
                return res.next
            min_val = p.val
            min_node_prev = prev
            while p.next:
                if p.next.val < min_val:
                    min_node_prev = p
                    min_val = p.next.val
                p = p.next
            t = min_node_prev.next
            min_node_prev.next = t.next

            s = prev.next
            prev.next = t
            prev.next.next = s

            prev = prev.next
